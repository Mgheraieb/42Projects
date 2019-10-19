<?php
	session_start();
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="Admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == "admin" && hash("sha256", $_SERVER['PHP_AUTH_PW']) == "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918") {
			include("includes/db.php");
?>
<style>
	.tox-notifications-container {
		display: none !important;
	}
</style>

<div class="container" style="padding-top: 25px;">
	<form action="admin.php?product" method="post" enctype="multipart/form-data">
		<table class="table table-sm table-borderless table-hover">
			<thead class="thead-dark">
				<tr>
					<td><h2>Liste des produits</h2></td>
				</tr>
				<tr>
					<th>ID</th>
					<th>Nom</th>
					<th>Categorie</th>
					<th>Description</th>
					<th>Prix</th>
					<th>Options</th>
					<th></th>
				</tr>
			</thead>
<?php
		$get_pro = "select * from products";
		$run_pro = mysqli_query($con, $get_pro);
		$i = 0;
		while ($row_pro = mysqli_fetch_array($run_pro)) {
			$pro_id = $row_pro['product_id'];
			$pro_title = $row_pro['product_title'];
			$pro_price = $row_pro['product_price'];
			$pro_desc = $row_pro['product_desc'];
			$pro_cat = $row_pro['product_cat'];
			$get_cat_pro = "select cat_title from categories where cat_id='$pro_cat'";
			$run_cat_pro = mysqli_query($con, $get_cat_pro);
			$i++;
?>
			<tr>
				<td><?php echo $i;?></td>
				<td><?php echo $pro_title;?></td>
				<td>
<?php
			while ($row_cat_pro = mysqli_fetch_array($run_cat_pro)) {
					$cat_title = $row_cat_pro['cat_title'];
					echo "$cat_title";
				}
?>
				</td>
				<td><small><?php echo $pro_desc;?></small></td>
				<td><?php echo $pro_price;?>€</td>
				<td><a href="admin.php?edit_product=<?php echo $pro_id;?>" style="text-decoration: none; color: white;"><button type="button" class="btn btn-sm btn-secondary">Editer</button></a></td>
				<td><a href="admin.php?remove_product=<?php echo $pro_id;?>" style="text-decoration: none; color: black;"><button type="button" class="btn btn-sm btn-warning">Supprimer</button></a></td>
			</tr>
<?php
		}
?>
		</table>
	</form>
	<form action="admin.php?product" method="post" enctype="multipart/form-data">
		<table class="table table-sm table-borderless">
			<tr>
				<td><h2>Ajouter un nouveau produit</h2></td>
			</tr>
			<tr>
				<td><b>Nom du produit</b></td>
				<td><input type="text" name="product_title" size="60" required/></td>
			</tr>
			<tr>
				<td><b>Categorie du produit</b></td>
				<td>
				<select name="product_cat">
					<option>Selectionner une categorie</option>
<?php
		$get_cats = "select * from categories";
		$run_cats = mysqli_query($con, $get_cats);
		while ($row_cats = mysqli_fetch_array($run_cats)) {
			$cat_id = $row_cats['cat_id'];
			$cat_title = $row_cats['cat_title'];
			echo "<option value='$cat_id'>$cat_title</option>";
		}
?>
				</select>
				</td>
			</tr>
			<tr>
				<td><b>Prix du produit</b></td>
				<td><input type="text" name="product_price" required/></td>
			</tr>
			<tr>
				<td><b>Description du produit</b></td>
				<td><textarea name="product_desc" cols="20" rows="10"></textarea></td>
			</tr>
			<tr align="right">
				<td colspan="3"><input type="submit" name="insert_post" value="Envoyer" class="btn btn-sm btn-secondary"></td>
			</tr>
		</table>
	</form>
</div>
<script src="https://cloud.tinymce.com/5/tinymce.min.js"></script>
<script>tinymce.init({selector:'textarea'});</script>
<?php
			if (isset($_POST['insert_post'])){
				$product_title = $_POST['product_title'];
				$product_cat= $_POST['product_cat'];
				$product_price = $_POST['product_price'];
				$product_desc = $_POST['product_desc'];
				$insert_product = "insert into products (product_cat,product_title,product_price,product_desc) values ('$product_cat','$product_title','$product_price','$product_desc');";
				$insert_pro = mysqli_query($con, $insert_product);
				if ($insert_pro)
					echo "<script>window.open('admin.php?product=add_success','_self')</script>";
			}
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

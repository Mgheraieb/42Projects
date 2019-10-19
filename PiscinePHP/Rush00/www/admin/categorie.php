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
<div class="container" style="padding-top: 25px;">
	<form action="admin.php?categorie" method="post" enctype="multipart/form-data">
		<table class="table table-sm table-borderless table-hover">
			<thead class="thead-dark">
				<tr>
					<td><h2>Liste des categories</h2></td>
				</tr>
				<tr>
					<th>ID</th>
					<th>Nom</th>
					<th>Option</th>
				</tr>
			</thead>
<?php
		$get_cat = "select * from categories";
		$run_cat = mysqli_query($con, $get_cat);
		$i = 0;
		while ($row_cat = mysqli_fetch_array($run_cat)) {
			$cat_id = $row_cat['cat_id'];
			$cat_title = $row_cat['cat_title'];
			$i++;
?>
			<tr>
				<td><?php echo $i;?></td>
				<td><?php echo $cat_title;?></td>
				<td><button type="button" class="btn btn-sm btn-warning"><a href="admin.php?remove_cat=<?php echo $cat_id;?>" style="text-decoration: none; color: black;">Supprimer</a></button></td>
			</tr>
<?php
		}
?>
		</table>
	</form>
	<form action="admin.php?categorie" method="post" enctype="multipart/form-data">
		<table class="table table-sm table-borderless">
			<tr>
				<td><h2>Ajouter une categorie</h2></td>
			</tr>
			<tr>
				<td><b>Nom de la categorie</b></td>
				<td><input type="text" name="cat_title" size="60" required/></td>
				<td><input type="submit" name="insert_post" value="Envoyer" class="btn btn-sm btn-secondary"></td>
			</tr>
		</table>
	</form>
</div>
<?php
			if (isset($_POST['insert_post'])){
				global $con;
				$get_cats = "select * from categories";
				$run_cats = mysqli_query($con, $get_cats);
				$cat_title = $_POST['cat_title'];
				while ($row_cats = mysqli_fetch_array($run_cats)) {
					if ($row_cats['cat_title'] == $cat_title) {
						echo "<script>window.open('admin.php?categorie=cat_error','_self')</script>";
						exit ();
					}
				}
				$insert_product = "insert into categories (cat_title) values ('$cat_title');";
				$insert_pro = mysqli_query($con, $insert_product);
				if ($insert_pro)
					echo "<script>window.open('admin.php?categorie=cat_success','_self')</script>";
			}
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>


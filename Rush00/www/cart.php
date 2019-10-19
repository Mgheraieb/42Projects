<?php
	session_start();
	$user = $_SESSION['loggued_on_user'];
	$con = mysqli_connect("192.168.99.100:3306","root","root","db_rush");
	function getIp() {
		$ip = $_SERVER['REMOTE_ADDR'];
		if (!empty($_SERVER['HTTP_CLIENT_IP']))
			$ip = $_SERVER['HTTP_CLIENT_IP'];
		else if (!empty($_SERVER['HTTP_X_FORWARDED_FOR']))
			$ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
		return $ip;
	}
?>

<style>
	.container {
		padding-top: 25px;
	}

	table {
		max-width: 960px;
		padding-top: 25px;
	}
	.effect {
		animation: launch 1s;
		opacity: 1;
	}
	@keyframes launch {
		0% {
			opacity: 0;
		}
		100% {
			opacity: 1;
		}
	}
</style>

<div class="effect">
	<div class="container">
		<form action="" method="post" enctype="multipart/form-data">
			<table class="table table-borderless">
				<thead class="thead-dark">
					<tr>
						<th>Selectionner</th>
						<th>Produit(s)</th>
						<th>Quantité</th>
						<th>Prix</th>
					</tr>
				</thead>
<?php
	$total = 0;
	global $con;
	$ip = getIp();
	$sel_price = "select * from cart where ip_add='$ip'";
	$run_price = mysqli_query($con, $sel_price);
	while ($p_price = mysqli_fetch_array($run_price)) {
		$pro_id = $p_price['p_id'];
		$pro_price = "select * from products where product_id='$pro_id'";
		$run_pro_price = mysqli_query($con,$pro_price);
		$pp_price = mysqli_fetch_array($run_pro_price);
		$product_price = array($pp_price['product_price']);
		$product_title = $pp_price['product_title'];
		$single_price = $pp_price['product_price'];
		$values = array_sum($product_price) * $p_price['qty'];
		$total += $values;
?>
				<tr>
					<th scope="row"><input type="checkbox" name="remove[]" value="<?php echo $pro_id;?>"/></th>
					<td><?php echo $product_title; ?></td>
					<td><?php echo $p_price['qty'];?></td>
					<td><?php echo "$" . $single_price; ?></td>
				</tr>
				<?php  } ?>
				<tr>
					<td colspan="3" align="right"><b>Prix total:</b></td>
					<td><?php echo "$" . $total;?> <small class="text-muted">/ mois</small></td>
				</tr>
				<tr align="right">
					<td><button type="submit" name="update_cart" class="btn btn-primary">Supprimer</button></td>
					<td><button type="submit" name="continue" class="btn btn-primary">Retour à la boutique</button></td>
					<td>
						<button class="btn btn-primary">
<?php
	if ($user != '') {
?>
							<a href="index.php?payment" style="text-decoration:none; color:white;">Commander</a>
<?php
	} else echo '<a href="index.php?signin=redir" style="text-decoration:none; color:white;">Commander</a>';
?>
						</button>
					</td>
				</tr>
			</table>
		</form>
	</div>
</div>
<?php
	function updatecart(){
		global $con;
		$ip = getIp();
		if (isset($_POST['update_cart'])) {
			foreach($_POST['remove'] as $remove_id) {
				$delete_product = "delete from cart where p_id='$remove_id' AND ip_add='$ip'";
				$run_delete = mysqli_query($con, $delete_product);
				if($run_delete)
					echo "<script>window.open('index.php?cart','_self')</script>";
			}
		}
		if (isset($_POST['continue']))
			echo "<script>window.open('index.php?products','_self')</script>";
	}
	echo @$up_cart = updatecart();
	if ($_GET['cart'] != null) {
		global $con;
		$ip = getIp();
		$pro_id = $_GET['cart'];
		$check_pro = "select * from cart where ip_add='$ip' AND p_id='$pro_id'";
		$run_check = mysqli_query($con, $check_pro);
		if (mysqli_num_rows($run_check) == 0) {
			$insert_pro = "insert into cart (p_id,ip_add,qty) values ('$pro_id','$ip', '1')";
			$run_pro = mysqli_query($con, $insert_pro);
			echo "<script>window.open('index.php?cart','_self')</script>";
		} else {
			$p_price = mysqli_fetch_array($run_check);
			$qty = $p_price['qty'] + 1;
			$edit_qty = "UPDATE cart SET qty ='$qty' WHERE ip_add='$ip' AND p_id='$pro_id';";
			$run_pro = mysqli_query($con, $edit_qty);
			echo "<script>window.open('index.php?cart','_self')</script>";
		}
	}
?>

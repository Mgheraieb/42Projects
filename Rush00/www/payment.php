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
		<h1>Commande finalisée 🤙🏻</h1>
		<table class="table table-borderless">
				<thead class="thead-dark">
					<tr>
						<th scope="col">Produit(s)</th>
						<th scope="col">Quantite</th>
						<th scope="col">Prix</th>
						<th></th>
					</tr>
				</thead>
<?php
	include("database/db.php");
	function getIp() {
		$ip = $_SERVER['REMOTE_ADDR'];
		if (!empty($_SERVER['HTTP_CLIENT_IP']))
			$ip = $_SERVER['HTTP_CLIENT_IP'];
		else if (!empty($_SERVER['HTTP_X_FORWARDED_FOR']))
			$ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
		return $ip;
	}
	$user = $_SESSION['loggued_on_user'];
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
		$product_id = $pp_price['product_id'];
		$pro_name = $pp_price['product_title'];
		$total += $product;
		$get_qty = "select * from cart where p_id='$pro_id'";
		$run_qty = mysqli_query($con, $get_qty);
		$row_qty = mysqli_fetch_array($run_qty);
		$qty = $row_qty['qty'];
		$values = array_sum($product_price) * $p_price['qty'];
		$p_total += $values;
		$insert_order = "insert into orders (p_id, c_name, qty, order_date) values ('$pro_id', '$user', '$qty', NOW())";
		$run_order = mysqli_query($con, $insert_order);
?>
				<tr align="center">
					<td><?php echo $pro_name; ?></td>
					<td><?php echo $p_price['qty'];?></td>
					<td><?php echo "$" . $values; ?></td>
				</tr>
<?php
	}
?>
				<tr>
					<td colspan="3" align="right"><b>Prix total:</b></td>
					<td><?php echo "$" . $p_total;?> <small class="text-muted">/ mois</small></td>
				</tr>
				<tr align="right">
					<td colspan="4">
						<a href="index.php" style="text-decoration:none; color:white;">
							<button class="btn btn-primary">
								Retour
							</button>
						</a>
					</td>
				</tr>
<?php
	$empty_cart = "DELETE from cart";
	$run_cart = mysqli_query($con, $empty_cart);
?>
		</table>
	</div>
</div>

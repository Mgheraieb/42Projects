<?php
	session_start();
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="Admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == "admin" && hash("sha256", $_SERVER['PHP_AUTH_PW']) == "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918") {
?>
<div class="container" style="padding-top: 25px;">
	<form action="admin.php?order" method="post" enctype="multipart/form-data">
		<table class="table table-sm table-borderless table-hover">
			<thead class="thead-dark">
				<tr>
					<td><h2>Liste des commandes</h2></td>
				</tr>
				<tr>
					<th>ID</th>
					<th>Client</th>
					<th>Produit</th>
					<th>Quantite</th>
					<th>Date</th>
					<th>Option</th>
				</tr>
			</thead>
<?php
		$get_order = "select * from orders";
		$run_order = mysqli_query($con, $get_order);
		while ($row_order = mysqli_fetch_array($run_order)) {
			$order_id = $row_order['order_id'];
			$qty = $row_order['qty'];
			$pro_id = $row_order['p_id'];
			$c_id = $row_order['c_id'];
			$c_name = $row_order['c_name'];
			$order_date = $row_order['order_date'];
			$get_pro = "select * from products where product_id='$pro_id'";
			$run_pro = mysqli_query($con, $get_pro);
			$row_pro = mysqli_fetch_array($run_pro);
			$pro_title = $row_pro['product_title'];
			$get_c = "select * from customers where customer_id='$c_id'";
			$run_c = mysqli_query($con, $get_c);
?>
			<tr>
				<td><?php echo $order_id;?></td>
				<td><?php echo $c_name;?></td>
				<td><?php echo $pro_title;?></td>
				<td><?php echo $qty;?></td>
				<td><?php echo $order_date;?></td>
				<td><input type="submit" name="delete_post" value="Supprimer" class="btn btn-sm btn-warning"></td>
			</tr>
<?php
		}
?>
		</table>
	</form>
</div>
<?php
			if (isset($_POST['delete_post'])) {
				$delete_id = $order_id;
				$delete_pro = "delete from orders where order_id='$delete_id'";
				$run_delete = mysqli_query($con, $delete_pro);
				if ($run_delete)
					echo "<script>window.open('admin.php?order=del_success','_self')</script>";
			}
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

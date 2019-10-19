<?php
	session_start();
	$auth_usr = "admin";
	$auth_pwd = "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918"; //password admin
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == $auth_usr && hash("sha256", $_SERVER['PHP_AUTH_PW']) == $auth_pwd) {
			if (isset($_GET['remove_product'])) {
				$delete_id = $_GET['remove_product'];
				$delete_pro = "delete from products where product_id='$delete_id'";
				$run_delete = mysqli_query($con, $delete_pro);
				if ($run_delete)
					echo "<script>window.open('admin.php?product=del_success','_self')</script>";
			}
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

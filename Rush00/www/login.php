<?php
	session_start();
	include ('auth.php');
	if ($_POST['login'] && $_POST['passwd'] && auth($_POST['login'], $_POST['passwd'])) {
		$_SESSION['loggued_on_user'] = $_POST['login'];
		if ($_GET['signin'] == 'redir')
			header('Location: /index.php?cart');
		else
			header('Location: /index.php?products');
	}
	else {
		$_SESSION['loggued_on_user'] = "";
		header('Location: /index.php?signin=error');
		exit ();
	}
?>

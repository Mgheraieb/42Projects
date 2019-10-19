<?php
	session_start();
	$db_link = mysqli_connect("192.168.99.100:3306", "root", "root");
	if ($db_link)
		if (!mysqli_select_db($db_link, "db_rush"))
			require 'database/install.php';
	include("database/db.php");
	$con = mysqli_connect("192.168.99.100:3306","root","root","db_rush");
?>

<!DOCTYPE html>
<html lang="fr">
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

		<link rel="stylesheet" href="assets/css/bootstrap.min.css">
		<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.2/css/all.css" integrity="sha384-oS3vJWv+0UjzBfQzYUhtDYW+Pj2yciDJxpsK1OYPAYjqT085Qq/1cq5FLXAZQ7Ay" crossorigin="anonymous">

		<link rel="icon" type="image/png" href="assets/img/favicon.png">

		<title>Minishop</title>
		<style>
			.card-footer > a {
				text-decoration: none;
				color: white;
			}
			.fa-store {
				color: #007bff;
			}
		</style>
	</head>
	<body>
		<nav class="navbar navbar-expand-lg navbar-light bg-light">
			<a class="navbar-brand text-secondary" href="index.php"><i class="fas fa-store"></i> Minishop</a>
			<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
			</button>

			<div class="collapse navbar-collapse" id="navbarSupportedContent">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item">
						<a class="nav-link" href="index.php">Accueil</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="index.php?products">Nos services</a>
					</li>
<?php
	if ($_SESSION['loggued_on_user'] != null) {
?>
					<li class="nav-item">
						<a class="nav-link" href="index.php?cart">Panier</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="index.php?account">Mon compte</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="logout.php">Se deconnecter</a>
					</li>
				</ul>
<?php
	} else {
?>
				<ul class="navbar-nav mr-auto">
					<li class="nav-item">
						<a class="nav-link" href="index.php?register">S'inscrire</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="index.php?signin">Se connecter</a>
					</li>
				</ul>
<?php
	}
?>
			</div>
		</nav>
<?php
	if ($_GET == null)
		include("home.php");
	if (isset($_GET['login']))
		include("login.php");
	if (isset($_GET['register']))
		include("register.php");
	if (isset($_GET['payment']))
		include("payment.php");
	if (isset($_GET['signin']))
		include("signin.php");
	if (isset($_GET['cart']))
		include("cart.php");
	if (isset($_GET['account']))
		include("account.php");
	if (isset($_GET['products']))
		include("products.php");
	if (isset($_GET['cat']))
		include("cat.php");
	if ($_GET['account'] == "edit_success")
		echo '	<div class="alert alert-success alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					<strong>Modification/Ajout</strong> reussit(e).
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['account'] == "edit_error")
		echo '	<div class="alert alert-danger alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Une <strong>erreur</strong> est survenue.
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['signin'] == "error")
		echo '	<div class="alert alert-danger alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Une <strong>erreur</strong> est survenue.
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['signin'] == "success")
		echo '	<div class="alert alert-success alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Felicitation votre <strong>compte</strong> a ete cree.
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['register'] == "error")
		echo '	<div class="alert alert-danger alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Une <strong>erreur</strong> est survenue.
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
?>
		<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
		<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
		<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
	</body>
</html>

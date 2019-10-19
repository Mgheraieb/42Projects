<?php
	session_start();
	include("../database/db.php");
	$auth_usr = "admin";
	$auth_pwd = "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918"; //password admin
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == $auth_usr && hash("sha256", $_SERVER['PHP_AUTH_PW']) == $auth_pwd) {
?>

<!DOCTYPE html>
<html lang="fr">
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

		<link rel="stylesheet" href="../assets/css/bootstrap.min.css">
		<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.2/css/all.css" integrity="sha384-oS3vJWv+0UjzBfQzYUhtDYW+Pj2yciDJxpsK1OYPAYjqT085Qq/1cq5FLXAZQ7Ay" crossorigin="anonymous">

		<link rel="icon" type="image/png" href="../assets/img/favicon-admin.png">

		<title>Admin Panel</title>
		<style>
			table {
				max-width: 960px;
			}
			.fa-user-shield {
				color: #ffc107;
			}
		</style>
	</head>
	<body>
		<nav class="navbar navbar-expand-lg navbar-light bg-light">
			<a class="navbar-brand text-secondary" href="admin.php"><i class="fas fa-user-shield"></i> Admin Dashboard</a>
			<button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
				<span class="navbar-toggler-icon"></span>
			</button>

			<div class="collapse navbar-collapse" id="navbarSupportedContent">
				<ul class="navbar-nav mr-auto">
					<li class="nav-item">
						<a class="nav-link" href="admin.php?product">Gestion des produits</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="admin.php?categorie">Gestion des categories</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="admin.php?user">Gestion des utilisateurs</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="admin.php?order">Gestion des commandes</a>
					</li>
					<li class="nav-item">
						<a class="nav-link" href="admin_logout.php">Se deconnecter</a>
					</li>
				</ul>
			</div>
		</nav>
<?php
	if (isset($_GET['edit_product']))
		include("edit_product.php");
	if (isset($_GET['product']))
		include("product.php");
	if (isset($_GET['remove_product']))
		include("remove_product.php");
	if (isset($_GET['categorie']))
		include("categorie.php");
	if (isset($_GET['remove_cat']))
		include("remove_cat.php");
	if (isset($_GET['order']))
		include("order.php");
	if (isset($_GET['remove_user']))
		include("remove_user.php");
	if (isset($_GET['user']))
		include("user.php");

	if ($_GET['categorie'] == "cat_error")
		echo '	<div class="alert alert-danger alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Une erreur est survenue
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['categorie'] == "cat_success")
		echo '	<div class="alert alert-warning alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Catégorie ajoutée avec succès
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['user'] == "add_success")
		echo '	<div class="alert alert-warning alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Utilisateur a été crée avec succès
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['user'] == "add_error")
		echo '	<div class="alert alert-danger alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Une erreur est survenue
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['user'] == "del_success")
		echo '	<div class="alert alert-warning alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Utilisateur supprimé avec succès
				<button type="button" class="close" data-dismiss="alert" aria-label="Close">
					<span aria-hidden="true">&times;</span>
				</button>
			</div>';
	if ($_GET['product'] == "add_success")
		echo '	<div class="alert alert-warning alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Produit ajouté avec succès
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['product'] == "del_success")
		echo '	<div class="alert alert-warning alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					Produit est supprimé avec succès
					<button type="button" class="close" data-dismiss="alert" aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>';
	if ($_GET['order'] == "del_success")
		echo '	<div class="alert alert-warning alert-dismissible fade show" role="alert" style="position: absolute; top: 75px; right: 25px;">
					La commande est supprimée avec succès
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
<?php
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

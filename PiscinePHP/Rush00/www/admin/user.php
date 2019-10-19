<?php
	session_start();
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="Admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == "admin" && hash("sha256", $_SERVER['PHP_AUTH_PW']) == "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918") {
?>
<div class="container"  style="padding-top: 25px;">
	<table class="table table-sm table-borderless table-hover">
		<thead class="thead-dark">
			<tr>
				<td><h2>Liste des utilisateurs</h2></td>
			</tr>
			<tr>
				<th>Nom d'utilisateur</th>
				<th>Option</th>
			</tr>
		<thead class="thead-dark">
<?php
		$data = unserialize(file_get_contents("../../private/passwd"));
			if ($data)
				foreach ($data as $key => $value) {
?>
		<tr>
			<td><?php echo $value["login"];?></td>
			<td><a href="admin.php?remove_user=<?php echo $value["login"];?>" style="text-decoration: none; color: black;"><button type="button" class="btn btn-sm btn-warning">Supprimer</button></a></td>
		</tr>
<?php
		}
?>
	</table>
	<form action="add_user.php" method="post">
		<table class="table table-sm table-borderless">
			<tr>
				<td><h2>Ajouter un utilisateur</h2></td>
			</tr>
			<tr>
				<td><input type="text" name="login" placeholder="Pseudonyme">
				<input type="text" name="passwd" placeholder="Mot de passe">
				<button type="submit" name="action" value="del_user" class="btn btn-sm btn-secondary">Ajouter</button></td>
			</tr>
		</table>
	</form>
</div>
<?php
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

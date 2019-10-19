<style>
	.login_container {
		display: -ms-flexbox;
		display: flex;
		-ms-flex-align: center;
		align-items: center;
		padding-top: 40px;
		padding-bottom: 40px;
	}

	.form-signin {
		width: 100%;
		max-width: 330px;
		padding: 15px;
		margin: auto;
	}
	.form-signin .checkbox {
		font-weight: 400;
	}
	.form-signin .form-control {
		position: relative;
		box-sizing: border-box;
		height: auto;
		padding: 10px;
		font-size: 16px;
	}
	.form-signin .form-control:focus {
		z-index: 2;
	}
	.form-signin input[type="email"] {
		margin-bottom: -1px;
		border-bottom-right-radius: 0;
		border-bottom-left-radius: 0;
	}
	.form-signin input[type="password"] {
		margin-bottom: 10px;
		border-top-left-radius: 0;
		border-top-right-radius: 0;
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
<?php
	if ($_GET['signin'] == 'redir') {
?>
<div class="effect">
	<div class="login_container">
		<form class="form-signin" action="login.php?signin=redir" method="POST">
			<h1 class="h1 mb-3 font-weight-normal">Connexion</h1>
			<label for="login" class="sr-only">Pseudonyme</label>
			<input type="text" id="login" name="login" class="form-control" placeholder="Pseudonyme" required autofocus>
			<label for="passwd" class="sr-only">Mot de passe</label>
			<input type="password" id="passwd" name="passwd" class="form-control" placeholder="Mot de passe" required>
			<button class="btn btn-lg btn-primary btn-block" type="submit" name="submit">Se connecter</button>
			<p class="mt-5 mb-3 text-muted">minishop &copy; 2019</p>
			<a href="admin/admin.php" style="text-decoration: none; color: #6c757d; padding-left: 70px;"><small pan class="text-muted">ADMIN PANEL <i class="fas fa-arrow-circle-right"></i></small></a></p>
		</form>
	</div>
</div>
<?php
	}
	else {
?>
<div class="effect">
	<div class="login_container">
		<form class="form-signin" action="login.php" method="POST">
			<h1 class="h1 mb-3 font-weight-normal">Connexion</h1>
			<label for="login" class="sr-only">Pseudonyme</label>
			<input type="text" id="login" name="login" class="form-control" placeholder="Pseudonyme" required autofocus>
			<label for="passwd" class="sr-only">Mot de passe</label>
			<input type="password" id="passwd" name="passwd" class="form-control" placeholder="Mot de passe" required>
			<button class="btn btn-lg btn-primary btn-block" type="submit" name="submit">Se connecter</button>
			<p class="mt-5 mb-3 text-muted">minishop &copy; 2019
			<a href="admin/admin.php" style="text-decoration: none; color: #6c757d; padding-left: 70px;"><small pan class="text-muted">ADMIN PANEL <i class="fas fa-arrow-circle-right"></i></small></a></p>
		</form>
	</div>
</div>
<?php
	}
?>

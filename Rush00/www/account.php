<style>
	.edit_container {
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

<div class="effect">
	<div class="edit_container">
		<form class="form-signin" action="edit.php" method="POST">
			<h1 class="h1 mb-3 font-weight-normal">Modifier mon mot de passe</h1>
			<label for="login" class="sr-only">Pseudonyme</label>
			<input type="text" id="login" name="login" class="form-control" placeholder="Pseudonyme" required autofocus>
			<label for="passwd" class="sr-only">Mot de passe</label>
			<input type="password" id="passwd" name="oldpw" class="form-control" placeholder="Mot de passe" required>
			<label for="passwd" class="sr-only">Nouveau Mot de passe</label>
			<input type="password" id="passwd" name="newpw" class="form-control" placeholder="Nouveau Mot de passe" required>
			<button class="btn btn-lg btn-primary btn-block" type="submit" name="submit">Modifier</button>
			<p class="mt-5 mb-3 text-muted">minishop &copy; 2019</p>
		</form>
	</div>
</div>

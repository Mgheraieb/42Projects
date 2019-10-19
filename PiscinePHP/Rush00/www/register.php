<style>
	.register_container {
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
	<div class="register_container">
		<form class="form-signin" action="create.php" method="POST">
			<h1 class="h1 mb-3 font-weight-normal">Inscription</h1>
			<label for="login" class="sr-only">Pseudonyme</label>
			<input type="text" id="login" name="login" class="form-control" placeholder="Pseudonyme" required autofocus>
			<label for="passwd" class="sr-only">Mot de passe</label>
			<input type="password" id="passwd" name="passwd" class="form-control" placeholder="Mot de passe" required>
			<button class="btn btn-lg btn-primary btn-block" type="submit" name="submit">S'inscrire</button>
			<p class="mt-5 mb-3 text-muted">minishop &copy; 2019</p>
		</form>
	</div>
</div>

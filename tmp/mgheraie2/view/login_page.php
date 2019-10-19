<?php
	include_once("../config/database.php");
	include_once("../config/pdo_init.php");
	include_once("../controller/login_authentication.php");
	include_once("../controller/submit_validation.php");
	//ON LANDING PAGE AUTHENTIFICATION AND NEW USER SUBMITTING THROUGH POST METHOD
	login_auth();
	submit_validation();
?>
<HTML>
<BODY>
	<h1>LOGIN FORM</h1>
	<form method="post">
		<input type="text" name="login" id="login" placeholder="Login">
		<input type="text" name="pwd" id="pwd" placeholder="Password">
		<input type="submit" name="login_go" value="login">
	</form>
	<h1>SUBMIT FORM</h1>
	<form method="post">
		<input type="text" name="new_login" id="new_login" placeholder="Login">
		<input type="text" name="new_pwd" id="new_pwd" placeholder="Password">
		<input type="submit" name="submit_go" value="submit">
	</form>
	
</BODY>
</HTML>

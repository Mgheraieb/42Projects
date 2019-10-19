<?php

function pdo_init()
{
	include("database.php");
	try {
		$dbh = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD, $DB_OPTIONS);
	}	catch (Exception $e) {
		echo 'Connection failed: ' . $e->getMessage();
	}
	return ($dbh);
}
?>

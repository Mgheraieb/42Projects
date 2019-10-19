<?php
	session_start();
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="Admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == "admin" && hash("sha256", $_SERVER['PHP_AUTH_PW']) == "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918") {
			if ($_POST['login'] != "" && $_POST['passwd'] != "") {
				if (file_exists("../../private") == false)
					mkdir ("../../private", 0777);
				if (file_exists('../../private/passwd') == false)
					file_put_contents('../../private/passwd', NULL);
				else {
					$data = unserialize(file_get_contents("../../private/passwd"));
					if ($data)
						foreach ($data as $key => $value)
							if ($value["login"] == $_POST["login"]) {
								header('Location: admin.php?user=add_error');
								exit ();
							}
				}
			}
			else {
				header('Location: admin.php?user=add_error');
				exit ();
			}
			$user["login"] = $_POST["login"];
			$user["passwd"] = hash('sha256', $_POST["passwd"]);
			$data[] = $user;
			file_put_contents("../../private/passwd", serialize($data));
			header('Location: admin.php?user=add_success');
			exit ();
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

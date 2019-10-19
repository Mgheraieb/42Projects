<?php
	session_start();
	$auth_usr = "admin";
	$auth_pwd = "8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918"; //password admin
	if (!isset($_SERVER['PHP_AUTH_USER'])) {
		header('WWW-Authenticate: Basic realm="admin"');
		header('HTTP/1.0 401 Unauthorized');
		exit();
	} else {
		if ($_SERVER['PHP_AUTH_USER'] == $auth_usr && hash("sha256", $_SERVER['PHP_AUTH_PW']) == $auth_pwd) {
			$users_file = file_get_contents("../../private/passwd");
			$users = unserialize($users_file);
			$action = "del_user";
			$login = $_GET['remove_user'];
				switch ($action) {
					case "del_user":
						if (!$login) {
							break;
						}
						foreach ($users as $key => $user) {
							if ($user['login'] == $login) {
								unset($users[$key]);
								break;
							}
						}
						break;
				}
			$out = serialize($users);
			file_put_contents("../../private/passwd", $out);
			$_GET["user"] = "del_success";
		} else {
			header('WWW-Authenticate: Basic realm="admin"');
			header('HTTP/1.0 401 Unauthorized');
		}
	}
?>

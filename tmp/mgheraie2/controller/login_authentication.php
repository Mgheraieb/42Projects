<?PHP
	function login_auth()
	{
		$_SESSION['signin_failure'] = false;
		$_SESSION['unvalidated_account'] = false;
		if ($_POST['login'] && $_POST['pwd'])
		{
			if ($dbh = pdo_init())
			{
				$request = $dbh->prepare("SELECT * FROM user WHERE `login` = :login_input");
				$request->execute(array(':login_input' => $_POST['login']));
				$result = $request->fetch();
				if (hash('whirlpool', $_POST['pwd']) == $result['hash_pwd'])
				{
					echo "login_successfull";
					$_SESSION['userlogin'] = $_POST['signin_login'];
				}
				else
				{
					echo "wrong login or pwd";
					$_SESSION['signin_failure'] = true;
				}
			}
		}
	}
?>

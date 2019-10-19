<?php
	
function check_info_signup($user_login, $user_passwd, $dbh)
{
	$request_login = $dbh->prepare("SELECT * FROM user WHERE `login` = :user_login");
	$request_login->execute(array(':user_login' => $user_login));
	if($request_login->rowCount())
	{
		$_SESSION['signup_login_failure'] = true;
		return (false);
	}
	if (strlen($user_passwd) < 8)
	{
		$_SESSION['sigup_pwd_failure'] = true;
		return (false);
	}	
	return (true);
}

function submit_validation()
{
if ($_POST['new_login'] && $_POST['new_pwd'] && $_POST['submit_go'])
	{
		if ($dbh = pdo_init())
		{
			if (check_info_signup($_POST['new_login'], $_POST['new_pwd'], $dbh))
			{
				$request = $dbh->prepare("INSERT INTO user (login, hash_pwd) VALUES (:userlogin, :userpwd)");
				$request->execute(array(':userlogin' =>$_POST['new_login'], ':userpwd' => hash('whirlpool', $_POST['new_pwd'])));
				$_SESSION['signup_success'] = true;
			}
		}
	}
}
?>

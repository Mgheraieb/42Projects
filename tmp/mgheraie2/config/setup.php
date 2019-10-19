<?php
include_once("database.php");
include_once("pdo_init.php");

if ($dbh = pdo_init())
{
	$request = $dbh->prepare('DROP TABLE `user`');
	$request->execute();
	$request = $dbh->prepare('DROP TABLE `basket`');
	$request->execute();
	$request = $dbh->prepare('DROP TABLE `product`');
	$request->execute();
	$request = $dbh->prepare('DROP TABLE `category`');
	$request->execute();

	//CREATING THE USER TABLE
	$request = $dbh->prepare('CREATE TABLE `user` (
	`userId` int(8) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`login` varchar(16) NOT NULL,
	`hash_pwd` varchar(128) NOT NULL
	)');
	$request->execute();

	//CREATING THE PRODUCT TABLE
	$request = $dbh->prepare('CREATE TABLE `product` (
	`productId` int(8) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`name` varchar(16) NOT NULL,
	`image` MEDIUMBLOB
	)');
	$request->execute();

	//CREATING THE CATEGORY TABLE
	$request = $dbh->prepare('CREATE TABLE `category` (
	`categoryId` int(8) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`name` varchar(16) NOT NULL
	)');
	$request->execute();

	//CREATING THE BASKET TABLE
	$request = $dbh->prepare('CREATE TABLE `basket` (
	`productId` int(8) NOT NULL,
	FOREIGN KEY (productId) REFERENCES product(productId)
	)');
	$request->execute();
}
else 
	echo("ERROR COULDN'T SETUP SQL DATABASE");

?>

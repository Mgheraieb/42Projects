<?php
	$db_host = "192.168.99.100:3306";
	$db_user = "root";
	$db_pw = "root";
	$db_name = "db_rush";
	$db_link = mysqli_connect($db_host, $db_user, $db_pw);

	function query_table($link, $table_name, $query) {
		if (mysqli_query($link, $query))
			echo "Requete '$table_name' effecute.\n";
		else
			die("Erreur de requete avec '$table_name'\n" . mysqli_error($link));
	}
	if (!$db_link)
		die("Connexion impossible: " . mysqli_connect_error());

	echo "Connexion avec le serveur MySQL reussite"."\n";

	if (mysqli_select_db($db_link, $db_name)) {
		echo "db_rush existe deja."."\n";
		exit();
	}

	$db_create = "CREATE DATABASE $db_name";

	if (mysqli_query($db_link, $db_create))
		echo "Database '$db_name' cree avec succes.\n";
	else
		throw_mysqli_error($db_link);

	mysqli_select_db($db_link, $db_name);

	$create_table_products = "CREATE TABLE products
		(product_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
		product_cat INT, product_title VARCHAR(40) DEFAULT 'item' NOT NULL,
		product_price INT NOT NULL, product_desc TEXT NOT NULL);";
	query_table($db_link, "products", $create_table_products);

	$create_table_categories = "CREATE TABLE categories
		(cat_id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
		cat_title TEXT NOT NULL);";
	query_table($db_link, "categories", $create_table_categories);

	$insert_products = "INSERT INTO products (product_cat,
		product_title, product_price, product_desc) VALUES
		(1, 'Minecraft', 5, '<p>Intel i5-9700F 4c 8t 2GHz<br>8GB DDR3 1333MHz<br>1x120Go SSD</p>'),
		(1, 'Left 4 Dead 2', 7, '<p>Intel i7-4790K 4c 8t 4GHz<br>16GB DDR3 1333MHz<br>1x120Go SSD</p>'),
		(1, 'CS:GO', 10, '<p>Intel i7-4790K 4c 8t 4GHz<br>16GB DDR3 1333MHz<br>1x240Go SSD</p>'),
		(1, 'TrackMania', 5, '<p>Intel i7-4790K 4c 8t 4GHz<br>8GB DDR3 1333MHz<br>1x120Go SSD</p>'),
		(1, 'Terraria', 7, '<p>Intel i5-9700F 4c 8t 2GHz<br>8GB DDR3 1333MHz<br>1x240Go SSD</p>'),
		(1, 'Dota 2', 10, '<p>Intel i7-4790K 4c 8t 4GHz<br>16GB DDR3 1333MHz<br>1x120Go SSD</p>'),
		(2, 'Mumble', 15, '<p>Intel i3-404NF 2c 8t 2GHz<br>4GB DDR3 1333MHz<br>1x60Go SSD</p>'),
		(2, 'TeamSpeak', 12, '<p>Intel i3-404NF 2c 8t 2GHz<br>6GB DDR3 1333MHz<br>1x60Go SSD</p>'),
		(3, 'Starter pack', 20, '<p>Intel i5-9700F 4c 8t 2GHz<br>8GB DDR3 1333MHz<br>1x240Go SSD</p>'),
		(3, 'Startup pack', 30, '<p>Intel i7-4790K 4c 8t 4GHz<br>16GB DDR3 1333MHz<br>1x500Go SSD</p>'),
		(3, 'Entreprise pack', 50, '<p>Intel i7-4790K 4c 8t 4GHz<br>16GB DDR4 1333MHz<br>1x1To SSD</p>'),
		(3, 'Data center', 150, '<p>Intel i10-7000 6c 8t 4GHz<br>32GB DDR4 1333MHz<br>5x1To SSD</p>');";
	query_table($db_link, "products", $insert_products);

	$insert_categories = "INSERT INTO categories (cat_id, cat_title) VALUES
		(1, 'Serveur gaming'), (2, 'Serveur vocal'), (3, 'Serveur web');";
	query_table($db_link, "categories", $insert_categories);

	$create_table_cart = "CREATE TABLE cart
		(p_id INT(10) PRIMARY KEY NOT NULL,
		ip_add VARCHAR(255) NOT NULL,
		qty INT DEFAULT 0 NOT NULL);";
	query_table($db_link, "cart", $create_table_cart);

	$create_table_order = "CREATE TABLE `orders`
	(`order_id` int(100) PRIMARY KEY AUTO_INCREMENT NOT NULL,
	`p_id` int(100) NOT NULL,
	`c_name` VARCHAR(255) NOT NULL,
	`qty` int(100) NOT NULL,
	`order_date` date NOT NULL);";
	query_table($db_link, "orders", $create_table_order);

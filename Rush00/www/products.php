<style>
	.container {
		max-width: 960px;
		padding-top: 25px;
	}
	.pricing-header {
		max-width: 700px;
	}
	.card-deck .card {
		min-width: 220px;
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
	<div class="container">
		<h4 style="padding-left: 10px;">Catégorie</h4>
		<ul class="nav nav-tabs">
<?php
	global $con;
	$get_cats = "select * from categories";
	$run_cats = mysqli_query($con, $get_cats);
	while ($row_cats=mysqli_fetch_array($run_cats)) {
		$cat_id = $row_cats['cat_id'];
		$cat_title = $row_cats['cat_title'];
		echo "
			<li class='nav-item'>
				<a class='nav-link' href='index.php?cat=$cat_id'>$cat_title</a>
			</li>
		";
	}
?>
		</ul>
	</div>
	<div class="container">
		<div class="card-deck mb-3 text-center">
<?php
	if (!isset($_GET['cat'])) {
		global $con;
		$get_pro = "select * from products";
		$run_pro = mysqli_query($con, $get_pro);
		while ($row_pro = mysqli_fetch_array($run_pro)) {
			$pro_id = $row_pro['product_id'];
			$pro_cat = $row_pro['product_cat'];
			$pro_brand = $row_pro['product_brand'];
			$pro_title = $row_pro['product_title'];
			$pro_price = $row_pro['product_price'];
			$pro_desc = $row_pro['product_desc'];
			echo "
			<div class='card mb-4 shadow-sm'>
				<div class='card-header'>
					<h4 class='my-0 font-weight-normal'>$pro_title</h4>
				</div>
				<div class='card-body'>
					<h1 class='card-title pricing-card-title'>$$pro_price <small class='text-muted'>/ mo</small></h1>
					<ul class='list-unstyled mt-3 mb-4'>
						<li>$pro_desc</li>
						</ul>
				</div>
				<div class='card-footer'>
					<a href='index.php?cart=$pro_id'><button type='button' class='btn btn-lg btn-block btn-outline-primary'>Ajouter au panier</button></a>
				</div>
			</div>
			";
		}
	}
?>
		</div>
	</div>
</div>

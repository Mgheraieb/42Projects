<style>
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
	<div class="pricing-header px-3 py-3 pt-md-5 pb-md-4 mx-auto text-center" style="max-width: 700px">
		<h1 class="display-4">Bienvenue <?php echo $_SESSION['loggued_on_user']; ?></h1>
		<p class="lead">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer sit amet nunc consectetur, auctor orci vitae, rhoncus lectus. Sed accumsan.</p>
	</div>
	<div class="container" stlye="max-width: 960px">
<?php
	if ($_SESSION['loggued_on_user'] != null) {
?>
			<div class="card-deck mb-3 text-center">
				<div class="card mb-4 shadow-sm">
				<div class="card-header">
					<h4 class="my-0 font-weight-normal">Minishop</h4>
				</div>
				<div class="card-body">
					<h1 class="card-title pricing-card-title">Installation <small class="text-muted">GRATUITE</small></h1>
					<ul class="list-unstyled mt-3 mb-4">
						<li>10 ans d'expérience</li>
						<li>Des serveurs performants</li>
						<li>Support téléphonique</li>
						<li>Communauté active</li>
					</ul>
				</div>
				<div class="card-footer">
					<a href="index.php?products" style="text-decoration:none; color:white;">
						<button class="btn btn-lg btn-block btn-primary">
							Voir la boutique
						</button>
					</a>
				</div>
			</div>
<?php
	} else {
?>
			<div class="card-deck mb-3 text-center">
				<div class="card mb-4 shadow-sm">
				<div class="card-header">
					<h4 class="my-0 font-weight-normal">Minishop</h4>
				</div>
				<div class="card-body">
					<h1 class="card-title pricing-card-title">Installation <small class="text-muted">GRATUITE</small></h1>
					<ul class="list-unstyled mt-3 mb-4">
						<li>10 ans d'expérience</li>
						<li>Des serveurs performants</li>
						<li>Support téléphonique</li>
						<li>Communauté active</li>
					</ul>
				</div>
				<div class="card-footer">
					<a href="index.php?register" style="text-decoration:none; color:white;">
						<button class="btn btn-lg btn-block btn-primary">
							S'inscire!
						</button>
					</a>
				</div>
			</div>
<?php }
	if (!isset($_GET['cat'])) {
		global $con;
		$get_pro = "select * from products order by RAND() LIMIT 0,3";
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

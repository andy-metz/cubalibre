<?php  
header('Content-Type: text/html; charset=utf-8');
include 'initialisation.php'; 
include'test.php';
?>
<html>

<head>
	<link rel="php" href="intialisation.php">
	<link rel="stylesheet" href="style.css">  
	<script type="text/javascript" src="jquery/external/jquery.js"></script> 
	<script type="text/javascript" src="jquery/jquery-ui.js"></script>
	<script type="text/javascript" src="../ServeurAJAX/interface_script.js"></script>
</head>
<body>

   <nav>
  <ul id="menu">
    <li>Accueil</li>
    <li>Recettes</li>
    <li>Mes favoris</li>
    <li>Trouver ma recette</li>
  </ul>
</nav>
   
<div class="display-section">   

	<div class="search_input_wrapper">
		<button class="add_search_input">Ajouter un aliment</button>
		
		<div><input type="text" name="SearchInput[]" class="autocomplete_button"></div>
	</div>
	<div id="empty-message"> </div>
		
</div>

</body>

</html>
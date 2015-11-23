<!DOCTYPE html>
<html>
<head>
<style>
table, th, td {
     border: 1px solid black;
}
</style>
</head>
<body>
<div>
<?php
	$servername ="127.0.0.1";
	$username ="root";
	$password ="";
	$db="mydb";

// Create connection
$conn = new mysqli($servername, $username, $password, $db);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT idRecette, LibRecette, ingredients, preparation FROM recette";
$result = $conn->query($sql);

if ($result->num_rows > 0) 
{
	echo "<select>\n";
    while($row = $result->fetch_assoc()) 
	{
		echo "<option value='".$row["LibRecette"]."'>".$row["LibRecette"]."</option>\n";
		//echo "<option value='".$row["LibRecette"]."'></option>\n";
		//echo $row["LibRecette"];
	}	
	echo "</select>";	
} 
else 
{
    echo "Pas de résultat";
}
$conn->close();
?> 
</div>
</body>
</html>

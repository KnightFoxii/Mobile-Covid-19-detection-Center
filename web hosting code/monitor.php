<?php
//This line will make the page auto-refresh each 15 seconds
$page = $_SERVER['PHP_SELF'];
$sec = "15";
?>


<html>
<head>
<!--//I've used bootstrap for the tables, so I inport the CSS files for taht as well...-->
<meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">		
<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
<!-- jQuery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<!-- Latest compiled JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
</head>
	
	
	
	
	
<body>    
<?php
include("database_connect.php");


// Check the connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$result = mysqli_query($con,"SELECT * FROM ESPtable2");//table select

		  
//loop through the table and print the data into the table
while($row = mysqli_fetch_array($result)) {
	
  // echo "<tr class='success'>"; 	
   // $unit_id = $row['id'];
   // echo "<td>" . $row['id'] . "</td>";
	
    $column1 = "RECEIVED_BOOL1";
    $column2 = "RECEIVED_BOOL2";
    $column3 = "RECEIVED_BOOL3";
    $column4 = "RECEIVED_BOOL4";
    $column5 = "RECEIVED_BOOL5";
	
    $current_bool_1 = $row['RECEIVED_BOOL1'];
	$current_bool_2 = $row['RECEIVED_BOOL2'];
	$current_bool_3 = $row['RECEIVED_BOOL3'];
	$current_bool_4 = $row['RECEIVED_BOOL4'];
	$current_bool_5 = $row['RECEIVED_BOOL5'];

	if($current_bool_1 == 1){
    $inv_current_bool_1 = 0;
	$text_current_bool_1 = "ON";
	$color_current_bool_1 = "#6ed829";
	}
	else{
    $inv_current_bool_1 = 1;
	$text_current_bool_1 = "OFF";
	$color_current_bool_1 = "#e04141";
	}
	
	
	if($current_bool_2 == 1){
    $inv_current_bool_2 = 0;
	$text_current_bool_2 = "ON";
	$color_current_bool_2 = "#6ed829";
	}
	else{
    $inv_current_bool_2 = 1;
	$text_current_bool_2 = "OFF";
	$color_current_bool_2 = "#e04141";
	}
	
	
	if($current_bool_3 == 1){
    $inv_current_bool_3 = 0;
	$text_current_bool_3 = "ON";
	$color_current_bool_3 = "#6ed829";
	}
	else{
    $inv_current_bool_3 = 1;
	$text_current_bool_3 = "OFF";
	$color_current_bool_3 = "#e04141";
	}
	
	
	if($current_bool_4 == 1){
    $inv_current_bool_4 = 0;
	$text_current_bool_4 = "ON";
	$color_current_bool_4 = "#6ed829";
	}
	else{
    $inv_current_bool_4 = 1;
	$text_current_bool_4 = "OFF";
	$color_current_bool_4 = "#e04141";
	}
	
	
	if($current_bool_5 == 1){
    $inv_current_bool_5 = 0;
	$text_current_bool_5 = "ON";
	$color_current_bool_5 = "#6ed829";
	}
	else{
    $inv_current_bool_5 = 1;
	$text_current_bool_5 = "OFF";
	$color_current_bool_5 = "#e04141";
	}
	
	
	
	
}
echo "</table>
<br>
";	
?>
		
		
<?php

include("database_connect.php");

if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$result = mysqli_query($con,"SELECT * FROM ESPtable2");//table select

	
echo "<table class='table' style='font-size: 30px;'>
	<thead>
		<tr>
		<th>Status of a patient </th>
		</tr>
	</thead>
    <tbody>
      <tr class='active'>
        <td>Temperature status </td>
        <td>Spo2 stats</td>
        <td>Sound status</td>
      </tr>  
		";
		  

while($row = mysqli_fetch_array($result)) {

 	echo "<tr class='info'>";
    
	echo "<td>" . $row['SENT_NUMBER_1'] . "</td>";
	echo "<td>" . $row['SENT_NUMBER_2'] . "</td>";
	echo "<td>" . $row['SENT_NUMBER_3'] . "</td>";
	//echo "<td>" . $row['SENT_NUMBER_4'] . "</td>";

	echo "</tr>
	</tbody>"; 

	
}
echo "</table>
<br>
";
?>
        <div class = "a">
		<form onsubmit = "return validate();" action="as1.html" name = "mandali" >
                  <font  font size = 6>Enter Patient Details : </font>
                      <br><br>
                    Temprature of the patient :<br>
                    <input type="text" name="firstname">
                    <br><br>
                  
                    Blood oxygen levels of the patient :<br>
                    <input type="text" name="lastname">
                      <br><br>
                       
                      
                     Check for following Symptoms :<br><br>
                     
                         
                      <input type="checkbox" name="sym1" value="y"> Shortness of breath or difficulty breathing<br>
                        <input type="checkbox" name="sym2" value="y"> Muscle aches <br>
                       <input type="checkbox" name="sym3" value="y" checked> Chills <br>
                        <input type="checkbox" name="sym4" value="y"> Sore throat<br>
                        <input type="checkbox" name="sym5" value="y"> Loss of taste or smell <br>
                       <input type="checkbox" name="sym6" value="y" checked> Headache<br>
                       <input type="checkbox" name="sym7" value="y" checked> Chest pain<br>
                      <br><br>
                     
                      
                      
                      <input type="submit" value="Submit">
                  </form>
		</div>
<style>
	div.a{

	width:500px; 
            height:auto; 
           
            border: 5px solid black;
            position: fixed; 
             font-weight: bold;
            top: 50%; 
            left: 40%; 
            margin-top: -100px; 
            margin-left: -100px; 
    background : rgb(100, 149, 237,0.8); text-align: center;
    
	}	
</style>		

		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
    
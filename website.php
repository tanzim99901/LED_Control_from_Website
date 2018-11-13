<?php
$LED = isset($_POST["led"]) ? $_POST["led"] : "";
//create a variable that will receive the state of LED
$Write_incoming="<p>Status : " . $LED . " </p>";
//create an HTML file to display the data within
file_put_contents('sensor.html',$Write_incoming);
if (isset($_GET["status"]))
{
	$Write_outgoing=$_GET["status"];
}
//create an HTML file to display the data within
file_put_contents('value.html',$Write_outgoing);
?>
<html>
	<head></head>
	<body onload="GetButton2()">
		<div>
			<!--<input type="button" id="LED2" onclick="GetButton1()" name="switch" color="red">-->
			<button type="button" id="LED2" onclick="GetButton1()" color="red">SWITCH</button>
		</div>
		<div id="myText"></div>
    </body>
	<script>
		strLED1 = "";
		strLED2 = "";
		var LED2_state = "0";
		var data_val = 0;
		var a = 10;
		var b = 2;
		function GetButton1()
		{	
			if (LED2_state === "1") {
				LED2_state = "0";
				localStorage.setItem("state", LED2_state);
			}
			else {
				LED2_state = "1";
				localStorage.setItem("state", LED2_state);
			}
			document.getElementById("myText").innerHTML = LED2_state;
			window.location.href = "website.php?status=" + LED2_state;
			//document.querySelector('.results').innerHTML = LED2_state;
		}
		function GetButton2()
		{	
			LED2_state = localStorage.getItem("state");
			document.getElementById("myText").innerHTML = LED2_state;
			//document.querySelector('.results').innerHTML = LED2_state;
		}
	</script>
</html>
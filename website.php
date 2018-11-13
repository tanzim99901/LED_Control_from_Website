<?php
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
		<div class="center">
			<!--<input type="button" id="LED2" onclick="GetButton1()" name="switch" color="red">-->
			<button type="button" id="LED2" onclick="GetButton1()" color="red" style="height:200px;width:200px">SWITCH</button>
		</div>
		<div class="center1" id="myText"></div>
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
<style>
.center {
  margin: 0;
  position: absolute;
  top: 50%;
  left: 50%;
  -ms-transform: translate(-50%, -50%);
  transform: translate(-50%, -50%);
}
.center1 {
  margin: 0;
  position: absolute;
  top: 55%;
  left: 50%;
  -ms-transform: translate(-50%, -50%);
  transform: translate(-50%, -50%);
}
</style>
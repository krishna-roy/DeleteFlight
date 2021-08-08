CancelSelected()
{

	web_reg_find("Text=Flights List", 
		LAST);

	web_add_header("Origin", 
		"http://{host_127_0_0_1_1080}");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_header("sec-ch-ua", 
		"\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"90\", \"Google Chrome\";v=\"90\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	lr_think_time(15);

	web_custom_request("itinerary.pl_2", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/itinerary.pl", 
		"Snapshot=t15.inf", 
		"Mode=HTTP", 
		"Body=flightID=26350-804-JB&2=on&flightID=300783-15473-JB&removeFlights.x=51&removeFlights.y=11&.cgifields=1&.cgifields=2", 
		LAST);

	return 0;
}

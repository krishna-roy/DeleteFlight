SignOff()
{

	web_reg_find("Text=Web Tours", 
		LAST);

	web_add_auto_header("sec-ch-ua", 
		"\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"90\", \"Google Chrome\";v=\"90\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(10);

	web_custom_request("welcome.pl_3", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/welcome.pl?signOff=1", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t16.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Text=Web Tours Navigation Bar", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("nav.pl_4", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/nav.pl?in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("home.html_2", 
		"URL=http://{host_127_0_0_1_1080}/WebTours/home.html", 
		"Method=GET", 
		"Resource=0", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t18.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	return 0;
}
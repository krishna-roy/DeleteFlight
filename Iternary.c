Iternary()
{

	web_reg_find("Text=Web Tours", 
		LAST);

	

	lr_think_time(11);

	web_custom_request("welcome.pl_2", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/welcome.pl?page=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Text=Web Tours Navigation Bar", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("nav.pl_3", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t13.inf", 
		"Mode=HTTP", 
		LAST);

/*Correlation comment - Do not change!  Original value='26350-804-JB' Name ='flightID' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=flightID",
		"RegExp=name=\"flightID\"\\ value=\"(.*?)\"\\ \\ ",
		"Ordinal=All",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

	web_custom_request("itinerary.pl", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/itinerary.pl", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t14.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);
	
	

	return 0;
}

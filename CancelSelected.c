CancelSelected()
{

	int i=0;
	
	int no_of_flights=lr_paramarr_len("flightID");
	
	char dynamicBody[5000]="";
	char* curr_Flight;
	
	for (i=0;i<no_of_flights;i++){
		
		curr_Flight=lr_paramarr_idx("flightID",i+1);
		strcat(dynamicBody,"flightID=");
		strcat(dynamicBody,curr_Flight);
		strcat(dynamicBody,"&");
		
		
	}
	
	
	
	
	lr_save_int(rand() % no_of_flights +1,"random_flight_seq");
	strcat(dynamicBody,lr_eval_string("{random_flight_seq}"));
	strcat(dynamicBody,"=on&removeFlights.x=51&removeFlights.y=11&.cgifields=1&.cgifields=2");
	lr_log_message(dynamicBody);
	
	lr_save_string(dynamicBody,"DynamicBody");
	
	
	//lr_exit(0,LR_AUTO);
	


	lr_think_time(15);
	web_reg_find("Text=Flights List", 
		LAST);

	web_custom_request("itinerary.pl_2",
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/itinerary.pl",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/itinerary.pl",
		"Snapshot=t15.inf",
		"Mode=HTTP",
		"Body={DynamicBody}",
		LAST);

	return 0;
}

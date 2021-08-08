Login()
{

	lr_save_string(lr_unmask("6084db9beb66eb6b"), "PasswordParameter");

	web_reg_find("Text=Web Tours", 
		LAST);

	

	lr_think_time(20);

	web_custom_request("login.pl",
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/login.pl",
		"Method=POST",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/nav.pl?in=home",
		"Snapshot=t9.inf",
		"Mode=HTTP",
		"Body=userSession={userSession}&username=jojo&password={PasswordParameter}&login.x=58&login.y=18&JSFormSubmit=on",
		LAST);

	web_reg_find("Text=Web Tours Navigation Bar", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("nav.pl_2", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/nav.pl?page=menu&in=home", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/login.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("login.pl_2", 
		"URL=http://{host_127_0_0_1_1080}/cgi-bin/login.pl?intro=true", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{host_127_0_0_1_1080}/cgi-bin/login.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	return 0;
}

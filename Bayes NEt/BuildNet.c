

#include <stdio.h>
#include <stdlib.h>
#include "Netica.h"
#include "NeticaEx.h"

#define CHKERR  {if (GetError_ns (env, ERROR_ERR, NULL))  goto error;}

environ_ns* env;

int main (void){
	net_bn* net = NULL;
	node_bn *Burglary, *Earthquake, *Alarm, *Johncalls, *Marycalls;
	char mesg[MESG_LEN_ns];
	int res;
	report_ns* err;
	
	env = NewNeticaEnviron_ns (NULL, NULL, NULL);
	res = InitNetica2_bn (env, mesg);
	printf ("%s\n", mesg);
	if (res < 0)  exit (-1);
	
	net = NewNet_bn ("Burglaryearthquake", env);
	CHKERR

	Burglary =    NewNode_bn ("Burglary", 2, net);
	Earthquake = NewNode_bn ("Earthquake", 2, net);
	Alarm =      NewNode_bn ("Alarm", 2, net);
	Johncalls =       NewNode_bn ("Johncalls", 2, net);
	Marycalls =       NewNode_bn ("Marycalls", 2, net);
	CHKERR

	SetNodeStateNames_bn (Burglary,   "true, false");
	SetNodeStateNames_bn (Earthquake,"true, false");
	SetNodeStateNames_bn (Alarm,     "true, false");
	SetNodeStateNames_bn (Johncalls,     "true, false");
	SetNodeStateNames_bn (Marycalls,     "true, false");
	
	CHKERR

	AddLink_bn (Burglary, Alarm);
	AddLink_bn (Earthquake, Alarm);
	AddLink_bn (Alarm, Johncalls);
	AddLink_bn (Alarm, Marycalls);
	CHKERR
	
	// WARNING: floats must be passed to SetNodeProbs, ie, 0.0 not 0

	SetNodeProbs (Burglary, 0.001, 0.999);
	SetNodeProbs (Earthquake, 0.002, 0.998);
	
	/*SetNodeProbs (Alarm, "true",    0.05, 0.95);
	SetNodeProbs (Tuberculosis, "no_visit", 0.01, 0.99);

	SetNodeProbs (Smoking, 0.5, 0.5);

	SetNodeProbs (Cancer, "smoker",    0.1,  0.9);
	SetNodeProbs (Cancer, "nonsmoker", 0.01, 0.99);

	SetNodeProbs (Bronchitis, "smoker",    0.6, 0.4);
	SetNodeProbs (Bronchitis, "nonsmoker", 0.3, 0.7);
	*/
	//                   Tuberculosis Cancer
	SetNodeProbs (Alarm, "true", "true", 0.95, 0.05);
	SetNodeProbs (Alarm, "true", "false",  0.94, 0.06);
	SetNodeProbs (Alarm, "false",  "true", 0.29, 0.71);
	SetNodeProbs (Alarm, "false",  "false",  0.001, 0.999);

	//                  TbOrCa  Abnormal Normal
	SetNodeProbs (Johncalls, "true",  0.90,  0.10);
	SetNodeProbs (Johncalls, "false", 0.05,  0.95);

	//                  TbOrCa  Abnormal Normal
	SetNodeProbs (Marycalls, "true",  0.70,  0.30);
	SetNodeProbs (Marycalls, "false", 0.01,  0.99);

	/*
	//                     TbOrCa   Bronchitis 
	SetNodeProbs (Dyspnea, "true",  "present", 0.9, 0.1);
	SetNodeProbs (Dyspnea, "true",  "absent",  0.7, 0.3);
	SetNodeProbs (Dyspnea, "false", "present", 0.8, 0.2);
	SetNodeProbs (Dyspnea, "false", "absent",  0.1, 0.9);
	*/
	CHKERR

	WriteNet_bn (net,  NewFileStream_ns ("Data Files\\Burglaryearthquake.dne", env, NULL));
	CHKERR

end:
	DeleteNet_bn (net);
	res = CloseNetica_bn (env, mesg);
	printf ("%s\n", mesg);
	printf ("Press <enter> key to quit ", mesg);
	getchar();
	return (res < 0 ? -1 : 0);

error:
	err = GetError_ns (env, ERROR_ERR, NULL);
	fprintf (stderr, "BuildNet: Error %d %s\n", 
	         ErrorNumber_ns (err), ErrorMessage_ns (err));
	goto end;
}


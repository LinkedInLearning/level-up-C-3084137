#include <stdio.h>
#include <time.h>

/* return the proper number of days in
   February for the current year */
int february(int year)
{
	if( (year%400)==0 )
		return(29);
	if( (year%100)==0 )
		return(28);
	if( (year%4)==0 )
		return(29);
	return(28);
}

/* apply proper ordinal suffix */
char *ordinal(int v)
{
	/* catch exceptions */
	if( v==11 || v==12 || v==13 )
		return("th");

	/* everything else is consistent */
	v %= 10;
	if( v==1 )
		return("st");
	if( v==2 )
		return("nd");
	if( v==3 )
		return("rd");
	return("th");
}

int main()
{
	time_t now;
	int months[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	char *mnames[] = { "January", "February", "March",
		"April", "May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	char *days[] = { "Sunday", "Monday", "Tuesday",
		"Wednesday", "Thursday", "Friday", "Saturday"
	};
	struct tm *today;
	int monday,mflag;

	/* gather time details */
	time(&now);
	today = localtime(&now);

	/* output today's info */
	printf("Today is %s, %s %d%s, %d\n",
			days[today->tm_wday],
			mnames[today->tm_mon],
			today->tm_mday,
			ordinal(today->tm_mday),
			today->tm_year+1900
		  );

	/* leap year adjustment */
	months[1] = february(today->tm_year+1900);

	/* calculate next Monday's offset */
		/* I formatted it this way so you can substitute
		   any day of the week. For example, for next
		   Wednesday, change the 1 in the next statement
		   to 3 for Wednesday. This is the only change
		   required */
	monday = ( 1 - today->tm_wday );
	if( monday<1 )
		monday += 7+today->tm_mday;
	else
		monday+=today->tm_mday;

	/* check to see if next Monday is in the next month */
	mflag = today->tm_mon;
	if(monday > months[today->tm_mon])
	{
		monday -= months[today->tm_mon];
		mflag++;
		mflag %= 12;		/* flip back to January */
	}

	printf("Next Monday will be the %d%s of %s\n",
			monday,
			ordinal(monday),
			mnames[mflag]
		  );

	return(0);
}

#include<stdio.h>
#include<stdlib.h>
//REMEMBER TO SAVE THIS IN USB DRIVE

int
holiday(int currentDate)
{
	return 	(currentDate==101||currentDate ==409||currentDate==414||currentDate ==415||currentDate==501||currentDate ==503||currentDate==612||currentDate ==709||currentDate==829||currentDate ==1130||currentDate==1225||currentDate ==1230);
	
}

int
specialD(int currentDate)
{
	return(currentDate==201||currentDate==225||currentDate==416||currentDate==509||currentDate==821||currentDate==1101||currentDate==1102||currentDate==1208||currentDate==1224||currentDate==1231);
}
int
restD(int currentDate,int case10,int case9,int case8,int case7,int case6,int case5,int case4,int case3,int case2,int case1,int case14)
{
	return (currentDate==case10||currentDate==case9||currentDate==case8||currentDate==case7||currentDate==case6||currentDate==case5||currentDate==case4||currentDate==case3||currentDate==case2||currentDate==case1||currentDate==case14);
}
// three functions above just return 1 if the current day is equal to another day 
float
bonusedD(int timeIn, int timeOut, float tSalary,int hours, float hSalary,float bonus,float nShiftbonus)// for bonused days
{ 


			int hours1=2360-timeIn, shiftH=0;
			float bdiff=nShiftbonus-bonus,num=0;
			
			
				if (hours1%100>=60)
				hours1+=40;
				
				
				if(nShiftbonus<bonus)
				num=nShiftbonus+bonus;//im assuming night shift has is gonna add the percentages of holiday and rest day together and special day and rest day together with night shift percentaesince not in pdf
				else if (bonus<nShiftbonus)
				num=bdiff;
				
				if(timeIn>=2200||timeIn<=600||timeOut>=2200||timeOut<=600)
						{
							if(timeIn<=600&&timeOut>600)
							shiftH=600-timeIn;
							else if(timeIn>=2200)
							shiftH=2360-timeIn;
							
							else if(timeOut<=600)
							shiftH=timeOut-timeIn;
							else if(timeOut>=2200)
							shiftH=timeOut-2200;
							
							
							if (shiftH%100>=60)
							shiftH+=40;
						}
				if(timeIn>timeOut)//means next day, meaning time in shift has the bonus=== 
				{
					
					
				
						tSalary+= bonus*hSalary*((hours1/100)+((hours1%100)/60.0000));
					
						
						
						//bottom is for night shift
						if(nShiftbonus<bonus&& timeIn>=2200||timeIn<=600&&nShiftbonus<bonus)
						{
							tSalary= tSalary/hSalary/bonus;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						else if (bonus<nShiftbonus)//the non restdays n special/holidays days
						{
								tSalary-=hSalary*((shiftH/100)+((shiftH%100)/60.00));
								tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						
				////////////////////////////////////////////////////////////////////
						
						
				////////////////////////////////////////////////////////////////////
			/*	///bottom is for night shift
							if(nShiftbonus<bonus&& timeOut>=2200||timeOut<=600&&nShiftbonus<bonus)
							{
							tSalary= ((tSalary-salad1)/bonus)/hSalary;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							
							tSalary+= salad1;
							}
					
							else if (bonus<nShiftbonus)//the non restdays n special/holidays days
							tSalary+=tSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							//////////////////////////////////////////////////////////// */
				}
				else if(timeOut>timeIn)//same day
				{	
					if(hours==800)
					{
						tSalary+= (hours/100)*hSalary*bonus;
					
					//bottom is for night shift
						if(nShiftbonus<bonus&& timeIn>=2200||timeIn<=600&&nShiftbonus<bonus)
						{
							tSalary= tSalary/hSalary/bonus;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						else if (bonus<nShiftbonus)//the non restdays n special/holidays days
						{
								tSalary-=hSalary*((shiftH/100)+((shiftH%100)/60.00));
								tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						
				////////////////////////////////////////////////////////////////////
						
					}
					
						
					
				 	else if(hours>800)//overtime
					{
					
						tSalary+=hSalary*bonus*8;
						tSalary+= hSalary*1.25*bonus*(((hours-800)/100)+(((hours%100)/60.00)));
						
				
						//bottom is for night shift
						if(nShiftbonus<bonus&& timeIn>=2200||timeIn<=600&&nShiftbonus<bonus)
						{
							tSalary= tSalary/hSalary/bonus;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						else if (bonus<nShiftbonus)//the non restdays n special/holidays days
						{
								tSalary-=hSalary*((shiftH/100)+((shiftH%100)/60.00));
								tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						
				////////////////////////////////////////////////////////////////////
						
				/*	///bottom is for night shift
							if(nShiftbonus<bonus&& timeOut>=2200||timeOut<=600&&nShiftbonus<bonus)
							{
							tSalary= ((tSalary-salad1)/bonus)/hSalary;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							
							tSalary+= salad1;
							}
					
							else if (bonus<nShiftbonus)//the non restdays n special/holidays days
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							////////////////////////////////////////////////////////////
					}*/}
					
					else if(hours<800)//undertime
					{
					
						
						tSalary+= hSalary*bonus*((hours/100)+((hours%100)/60.00));
						
				
						//bottom is for night shift
						if(nShiftbonus<bonus&& timeIn>=2200||timeIn<=600&&nShiftbonus<bonus)
						{
							tSalary= tSalary/hSalary/bonus;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						else if (bonus<nShiftbonus)//the non restdays n special/holidays days
						{
								tSalary-=hSalary*((shiftH/100)+((shiftH%100)/60.00));
								tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
						}
					
						
				////////////////////////////////////////////////////////////////////
						
					}
					
				
				}	
					
	return tSalary;
}
float
bonusedD2(int timeIn, int timeOut, float tSalary,int hours, float hSalary,float bonus,float nShiftbonus,float salad1)// part2
{
	int shiftH=0, hours1=2360-timeIn;// shift hours
	float num=0;
	float bdiff=abs(nShiftbonus-bonus);
	
	
	
				if (hours1%100>=60)
				hours1+=40;
				
				
				
				if(nShiftbonus<bonus)
					num=nShiftbonus+bonus;//im assuming night shift has is gonna add the percentages of holiday and rest day together and special day and rest day together with night shift percentaesince not in pdf
				else if (bonus<nShiftbonus)
					num=bdiff;
				
				
				
					if(timeOut>=2200||timeOut<=600)//this is to put a value on my shiftH variable, it carries how many hours do i multiply by the new night shift bonus
						{
							if(timeOut<=600)
							shiftH=timeOut;
							else if(timeOut>=2200)
							shiftH=timeOut-2200;
							
							if (shiftH%100>=60)
							shiftH+=40;
						}
					if(hours==800)
					{
						tSalary+= ((timeOut/100)+((timeOut%100)/60))*hSalary*bonus;
							
						///bottom is for night shift
							if(nShiftbonus<bonus&& timeOut>=2200||timeOut<=600&&nShiftbonus<bonus)
							{
							tSalary= ((tSalary-salad1)/bonus)/hSalary;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							
							tSalary+= salad1;
							}
					
							else if (bonus<nShiftbonus)//the non restdays n special/holidays days
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
							////////////////////////////////////////////////////////////
					}
				
			
					
					else if(hours>800)// overtime
					{	
					
						//first tSalary is the amount the second part without overtime
						tSalary+=  (timeOut/100) *hSalary*bonus;
					
						
						///bottom is for night shift
							if(nShiftbonus<bonus&& timeOut>=2200||timeOut<=600&&nShiftbonus<bonus)
							{
							tSalary= ((tSalary-salad1)/bonus)/hSalary;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							
							tSalary+= salad1;
							}
					
							else if (bonus<nShiftbonus)//the non restdays n special/holidays days
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
							////////////////////////////////////////////////////////////
							
						tSalary+= ( ( ( (hours1+timeOut)-800) /100)+((((hours1+timeOut)-800)%100)/60.00))*hSalary*bonus*1.25;//overtime calculation
					}
					else if(hours<800)//undertime
					{
			///bottom is for night shift
							if(nShiftbonus<bonus&& timeOut>=2200||timeOut<=600&&nShiftbonus<bonus)
							{
							tSalary= ((tSalary-salad1)/bonus)/hSalary;
							
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*num;
							
							tSalary+= salad1;
							}
					
							else if (bonus<nShiftbonus)//the non restdays n special/holidays days
							tSalary+=hSalary*((shiftH/100)+((shiftH%100)/60.00))*(1+num);
							////////////////////////////////////////////////////////////
					}
				return tSalary;
}
/////////////////////
int
dayCounter(int month1, int day1,int month2, int day2) // counts the days
{
	int month,temp=0,o;
	
	for(month=month1;month<=month2;month++)
	{
			if(month1==month2)
		{
			temp+=1+day2-day1;
		}
		else
		if(month==2)
		{
			o=29;
			if(month==month1)
			temp+=o-day1;
		}
		else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
				o=32;
			if(month==month1)
			temp+=o-day1;
		}
		else if(month==4||month==6||month==9||month==11)
		{
				o=31;
			if(month==month1)
			temp+=o-day1;
		}
	
		else
		o=0;
		
		if(month2==month&&month1!=month2)
		temp+=day2;
		else if(month!=month1)
		temp+=o-1;
	}
	return temp;
}

int
daysoftheMonths(int month1, int day1,int month2, int day2, int case10,int case9,int case8,int case7,int case6,int case5,int case4,int case3,int case2,int case1,float dSalary)//will call the computation functions
{// cases are the rest dates...
	int totalDays,i,currentDate=0,o,timeIn,timeOut,hours=0,prevTout=-1, hours1,cworkDays=1,case14=0;// consecutive workdays,case 14 will be current date if 7th day in a row
	
	float hSalary=dSalary/8,tSalary=0,ttSalary=0,bonus=0, salad1;
	
	totalDays=dayCounter( month1,  day1, month2,  day2);
	printf("\n\n//////////////////////////////////////////////////////////////////////////////////////\nINPUT THE TIME IN AND TIME OUT FOR THIS EMPLOYEE FOR EVERYDAY IN THE TIME PERIOD\n");//\n-----------------------------------------------\n

	for(i=1,currentDate=month1*100+day1;i<=totalDays;i++,currentDate++,cworkDays++)//current date is a 4-3 digit num first 2 digi s month last 2 is days// everyday for loop
	{
			if(currentDate/100==2)//feb
				o=29;//+1 cause includes day its on
			else if(currentDate/100==1||currentDate/100==3||currentDate/100==5||currentDate/100==7||currentDate/100==8||currentDate/100==10||currentDate/100==12)//months of31
				o=32;
			else if(currentDate/100==4||currentDate/100==6||currentDate/100==9||currentDate/100==11)//months of30
					o=31;
						
		if(currentDate%100==o)
		{
			currentDate+=101-o;// switches to next month
		}
		
		printf("\n------------------------------------------------------------------------------------\n||DATE:%d/%d/2022||day: %d\nplease input in military time\n-----------------------------------------------\n",currentDate/100,currentDate%100,i);//will show what the month and day is............... :} A
	do{
		
		do
		{
		printf("Time in: ");
		scanf("%d",&timeIn);
		
		if(timeIn<0||timeIn%100>59||timeIn>2359)
			printf("\n[ERROR] PLEASE INPUT A VALID TIME IN MILITARY TIME FORMAT [ERROR]\n" );
		if(prevTout>=timeIn&&timeIn!=0)
			printf("\n[ERROR] TIME IN CAN NOT BE LESSER THAN OR EQUAL TO PREVIOUS TIME OUT [ERROR]\n" );
			
		}while(timeIn<0||timeIn%100>59||timeIn>2359||prevTout>=timeIn&&timeIn!=0);

		do
		{
		printf("Time out: ");
		scanf("%d",&timeOut);
		
		
		if(timeOut<0||timeOut%100>59||timeOut>2359)
			printf("\n[ERROR] PLEASE INPUT A VALID TIME IN MILITARY TIME FORMAT[ERROR]\n" );
		}while(timeOut<0||timeOut%100>59||timeOut>2359);
		
		
		if(prevTout>=timeIn&&timeOut!=0)
			printf("\n[ERROR] TIME IN CAN NOT BE LESSER THAN OR EQUAL TO PREVIOUS TIME OUT [ERROR]\n" );
		if(timeIn==timeOut&&timeIn!=0)
			printf("\n[ERROR] EMPLOYEE CANNOT WORK FOR LESS THAN A MINUTE [ERROR]\n");
	}while(prevTout>=timeIn&&timeOut!=0||timeIn==timeOut&&timeIn!=0);
	
	
		
		
		if(timeOut==0&&timeIn==0)//resets counter on how many days worked conescutivleygat
		cworkDays=0;
		if(cworkDays==7)
		{
			cworkDays=0;
			case14=currentDate;
		}
		
		//CALCULATES HOW MANY HOURS THEY TIMED IN N OUT THEN USES THAT FOR SALARY [SALARY WILL BE CALCULATED BY CHECKING HOURS AND THEN CHECKING IF CURRENT DATE IS A HOLIDAY OR REST DAY OR SMTN IN A SWITCH CASE]
		if(timeIn>timeOut)//means next day
		{
			hours=2360-timeIn+timeOut;//2400-40 cause an hour is 60 min so it woul go to 60 later gonna make %100 of hours add 100 so that it can increment hours instead of being 60 ex. instead of 560 it will be 600
			hours1= 2360-timeIn;
			prevTout=timeOut;
		
		}
		else if(timeOut>timeIn)//same day
		
		
		{
			hours=timeOut-timeIn;
			hours1=timeOut-timeIn;
		}
			
		
		if (hours%100>=60)
		{
			hours+=40;// adds to hour so if time is 2260 its would go to 2300
		}
		
		
		
		 if (timeIn==0&&timeOut==0)
		tSalary+=0;
		
		
				if (hours1%100>=60)
				hours1+=40;
		
		
		
	
		
	
		//Rest  Day|||||||||||||||||||||||||||||||||special n holidays
			if(restD(currentDate,case10,case9,case8,case7,case6,case5,case4,case3,case2,case1,case14)==1)//if present day is special day
			{		
					if(specialD(currentDate)==1)
					{
						tSalary=bonusedD(timeIn,timeOut,tSalary,hours,hSalary,1.5,1.43);// special days and rest days together are 50%
						salad1=tSalary;
					}
						
						
					else if(holiday(currentDate)==1)
					{
						tSalary=bonusedD(timeIn,timeOut,tSalary,hours,hSalary,2.6,2.20);// holidays on rest days are 160%
							salad1=tSalary;
							tSalary+=((800-hours1)/100)*50;
					}
					
					else
						tSalary=bonusedD(timeIn,timeOut,tSalary,hours,hSalary,1.3,1.43);// rest days are 30%
						salad1=tSalary;

			}
			
			else if	(holiday(currentDate)==1)// if present date is  a holiday
			{
				tSalary=bonusedD(timeIn,timeOut,tSalary,hours,hSalary,2,2.20);//holidays are x2
					salad1=tSalary;
					tSalary+=((800-hours1)/100)*50;
			}
			else if(specialD(currentDate)==1)//if present day is special day
			{
					tSalary=bonusedD(timeIn,timeOut,tSalary,hours,hSalary,1.3,1.43);// special days are 30%	
					salad1=tSalary;
			}
			else 
			{
				tSalary=bonusedD(timeIn,timeOut,tSalary,hours,hSalary,1,1.1);
				salad1=tSalary;
			}
			
			/////bonusedD2 partss  [second half when first half is donee]
			 if (restD(currentDate+1,case10,case9,case8,case7,case6,case5,case4,case3,case2,case1,case14)==1&& timeIn>timeOut)
			{
					if(specialD(currentDate+1)==1)
					{
						tSalary=bonusedD2(timeIn,timeOut,tSalary,hours,hSalary,1.5,1.43,salad1);// special days and rest days together are 50%
					
					}
						
						
					else if(holiday(currentDate+1)==1)
					{
					//	printf("\n%.2f",tSalary);//[test]
						tSalary=bonusedD2(timeIn,timeOut,tSalary,hours,hSalary,2.6,2.2,salad1);// holidays on rest days are 160%
					
					}
						
					else
						tSalary=bonusedD2(timeIn,timeOut,tSalary,hours,hSalary,1.3,1.43,salad1);
			}
			
			else if(holiday(currentDate+1)==1&& timeIn>timeOut)//if next day is the holiday n time in is greater than time out
			{
				tSalary=bonusedD2(timeIn,timeOut,tSalary,hours,hSalary,2,2.20,salad1);
			
			}
			else if ((specialD(currentDate+1))==1&& timeIn>timeOut)
			{
					tSalary=bonusedD2(timeIn,timeOut,tSalary,hours,hSalary,1.3,1.43,salad1);
				
			}
		
			else if(timeIn> timeOut )
				tSalary=bonusedD2(timeIn,timeOut,tSalary,hours,hSalary,1,1.1,salad1);
				
			
			
			// totaltotal salary
			ttSalary+=tSalary;
			printf("\nsalary this shift: %.2f",tSalary);
		
		
				
			tSalary=0;//reset to 0 and i have total total salary so that i dont duplicate values on special days or holidays or rest days 
	
	
			printf("\ntotal salary: %.2f\n",ttSalary);
			}			
	
	}
	



int
askDay(int month,int month1,int month2,int day1, int day2)
{
	int day,x;
	//checks the month
		if(month==2)
		x=28;
		else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		x=31;
		else if(month==4||month==6||month==9||month==11)
		x=30;
	
	do{
		
	printf("\nInput the a DAY in this month: ");
	scanf("%d",&day);
	if(day1!=-1)
	day2=day;
	
	if(day>x||day<1)
	printf("\n[ERROR] DAY DOES NOT EXIST, PLEASE INPUT A VALID DAY WITHIN THIS MONTH [ERROR]\n" );
	else if(month2==month1&&day1>day2)
	printf("\n[ERROR] ENDING DAY CAN NOT BE BEFORE STARTING DAY [ERROR]\n" );
	
	}while(day>x||day<1||month2==month1&&day1>day2);
	return day;
}


int
askRestDay(int x, int rest, int month1, int month2,int day1,int day2)
{
	int rdate, rday,temp;
	temp=dayCounter( month1,  day1, month2,  day2);// to count how many days in the months

			printf("\n================INPUTS===================\n[1] January\t\t\t[2] Febuary\n[3] March\t\t\t[4] April\n[5] May\t\t\t\t[6] June\n[7] July\t\t\t[8] August\n[9] September\t\t\t[10] October\n[11] November\t\t\t[12] December\n=========================================");
			do{
			
			printf("\nInput a VALID MONTH for rest day %d: ",x);
			scanf("%d",&rdate);
			
			if(rdate<month1||rdate>month2||rdate<1||rdate>12)
			{
			printf("\n#############################################################\n[ERROR] PLEASE INPUT A MONTH WITHIN THE TIME PERIOD [ERROR]\n");
			printf("\n==============TIME PERIOD===============\n%d/%d/2022 to %d/%d/2022||number of days: %d\n========================================\n\n#############################################################\n", month1,day1,month2,day2,temp);
			}
			}
			while(rdate<month1||rdate>month2||rdate<1||rdate>12);
			
			
			rdate*=100;//month is first 2 digitsof a numb ex. 0400 for april,1200 for dec
			
			// days down here
			do{
			printf("\nInput a VALID DAY for rest day %d: ",x);
			scanf("%d",&rday);
			
			if(rday<day1&&month1==month2||rday>day2&&month1==month2)
			{
			
			printf("\n#############################################################\n[ERROR] PLEASE INPUT A DAY WITHIN THE TIME PERIOD [ERROR]\n");
			printf("\n==============TIME PERIOD===============\n%d/%d/2022 to %d/%d/2022||number of days: %d\n========================================\n\n#############################################################\n", month1,day1,month2,day2,temp);
			}
			}
			while(rday<day1&&month1==month2||rday>day2&&month1==month2);
			rdate+=rday;
			
			
			return rdate;
}




//pplfuncpplplplplplplplplpppl
pplFunc(int ppl,int month1,int day1,int month2,int day2)
{
	float dSalary;
	int i,x=10,rest,a=0,s=0,d=0,f=0,g=0,h=0,j=0,k=0,l=0,z=0;//
	
	printf("\n-----------------------------------------------\n");
	
	for(i=1;i<=ppl;i++)
	{
		do{
		printf("\n||EMPLOYEE %d||\nInput the daily salary rate of this employee: ", i);//ask for salary
		scanf("%f",&dSalary);
		if(dSalary<1)
			printf("\n#############################################################\n[ERROR] EMPLOYEE CAN NOT WORK FOR FREE [ERROR]\n#############################################################\n");
		}while(dSalary<1);
	
		do //asking for rest days 
		{
		printf("\n==============================================================================================\n|EMPLOYEE %d| has 10 rest days available,\ninput how many rest days this employee used: ", i);
		scanf("%d",&rest);
		
		
		if(rest<0||rest>x)
		printf("\n#############################################################\n[ERROR] PLEASE INPUT A VALID NUMBER OF REST DAYS [ERROR]\n#############################################################\n");
		if(month1==month2&&(day1-1)+rest>day2||  month1+1==month2&&month1==1&&(day1+rest)-32>day2||month1+1==month2&&month1==3&&(day1+rest)-32>day2||month1+1==month2&&month1==5&&(day1+rest)-32>day2||month1+1==month2&&month1==7&&(day1+rest)-32>day2||month1+1==month2&&month1==8&&(day1+rest)-32>day2||month1+1==month2&&month1==10&&(day1+rest)-32>day2||month1+1==month2&&month1==12&&(day1+rest)-32>day2|| month1+1==month2&&month1==4&&(day1+rest)-31>day2||month1+1==month2&&month1==6&&(day1+rest)-31>day2||month1+1==month2&&month1==9&&(day1+rest)-31>day2||month1+1==month2&&month1==11&&(day1+rest)-31>day2||month1+1==month2&&month1==2&&(day1+rest)-29>day2)
		printf("\n#############################################################\n[ERROR] REST DAYS CANNOT BE MORE THAN WORKING DAYS [ERROR]\n#############################################################\n");
	
		} while(rest<0||rest>x);
		
		switch(rest)
		{
			case 10:x=10;
					z=askRestDay(x,rest,month1, month2,day1,day2);
			case 9:	x=9;
					l=askRestDay(x,rest,month1, month2,day1,day2);
			case 8:	x=8;
					k=askRestDay(x,rest,month1, month2,day1,day2);
			case 7:	x=7;
					j=askRestDay(x,rest,month1, month2,day1,day2);
			case 6:	x=6;
					h=askRestDay(x,rest,month1, month2,day1,day2);
			case 5:	x=5;
					g=askRestDay(x,rest,month1, month2,day1,day2);
			case 4:	x=4;
					f=askRestDay(x,rest,month1, month2,day1,day2);
			case 3:	x=3;
					d=askRestDay(x,rest,month1, month2,day1,day2);
			case 2:	x=2;
					s=askRestDay(x,rest,month1, month2,day1,day2);
			case 1:	x=1;
					a=askRestDay(x,rest,month1, month2,day1,day2);
					break;
			case 0: printf("\nno rest days");
					break;
			
		}
		daysoftheMonths(month1,  day1, month2, day2,z,l,k,j,h,g,f,d,s,a,dSalary);
	}
}


//=======================================================================================
int
timePeriod(char s[],int month1, int month2) //input for time period
{
	int date;
	do{
		printf("\n================INPUTS===================\n[1] January\t\t\t[2] Febuary\n[3] March\t\t\t[4] April\n[5] May\t\t\t\t[6] June\n[7] July\t\t\t[8] August\n[9] September\t\t\t[10] October\n[11] November\t\t\t[12] December\n=========================================");
		printf("\nInput the %s MONTH: ",s);
		scanf("%d",& date);
		
		if(month1>0&&month1<13)
		month2=date;
		
		if(month2<month1)
		printf("\n#############################################################\n[ERROR] ENDING MONTH CANNOT BE LESS THAN STARTING MONTH [ERROR]\n#############################################################\n");
		if(date<1||date>12)
		printf("\n#############################################################\n[ERROR] PLEASE INPUT A MONTH THAT IS VALID [ERROR]\n#############################################################\n");
	}
	while(date<1||date>12||month2<month1);
	

	
	return date;
	
}




int
main(){
	char s[50];

	int month1, month2,day1,day2,ppl,month,o=0,temp=0;
	printf("This C program that will compute for the salary of employees for an inputted period of time following actual Philippine law.\n");
	
	//time period stuff down here
	month1=timePeriod("STARTING",-1,13);
	day1=askDay(month1,-1,13,-1,100);
	
	
	month2=timePeriod("ENDING",month1,13);
	day2=askDay(month2,month1,month2,day1,100);
	
	temp=dayCounter( month1,  day1, month2,  day2);// to count how many days in the months

	printf("\n==============TIME PERIOD===============\n%d/%d/2022 to %d/%d/2022||number of days: %d\n========================================\n", month1,day1,month2,day2,temp);
	
	//EMPLOYEE COUNT
	do{

	printf("\ninput how many employees' salaries will be computed: ");
	scanf("%d", &ppl);
	if(ppl<0)
	printf(	"\n[ERROR] YOU CAN NOT HAVE NEGATIVE EMPLOYEES [ERROR]\n");
	else if(ppl==0)
	printf(	"\n[ERROR] YOU CAN NOT HAVE ZERO EMPLOYEES [ERROR]\n");
	}while(ppl<1);
	
	pplFunc(ppl,month1,day1,month2,day2);//for loop func for amount of employees
	
	printf("\n||PROGRAM DONE||");
}

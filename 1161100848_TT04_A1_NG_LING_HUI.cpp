
/**********|**********|**********|
Program: TT04_A2_NG_LING_HUI.cpp
Course: TCP1101 Programming Fundamentals
Year: 2017/18 Trimester 1
Student Name: Ng Ling Hui
Student ID: 1161100848
Email: abouterimi@hotmail.com
Phone: 017-6812560
**********|**********|**********/

#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <cstring>
using namespace std;

int main()
{
	string text[90]={"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""},file_name,selection ;
	int reselect=1,r,column,enterFunction,tile_int,cnum=4,textnum=1,num=1,text_length,totalr=5;
	bool valid=false;
	string word,temporaly,stext,cal_num_input,findtext="FindTextEmpty",newpaste,textcopy,undo[90];
	int copynum,longestr4,longestr6,longestr8,longestr10,longestr12,longestr14,longestr16,longestr18;
//------------------------------------------------------------------------------------------------------------------------------------
	
	file_name= "NULL";	//set initial file name as NULL
	cout<<"* ============================================\n"<<endl;
	cout<< "File name:"<<file_name<<endl;  //print file name
	
//------------------------------------------------------------------------------------------------------------------------------------
		
	while (reselect==1) //while loop to choose N,I,D,O
	{	
		cout<<"[N]ew,[I]nsert,[D]elete,[O]verwrite,[L]oad,[S]ave,[C]opy,show_clip[B]oard,[X]cut,[P]aste,[F]ind,[U]ndo,[Q]uit\n"<<"==>";
		cin>>selection;
		reselect=0;
		num=1;
		r=1;
		column=1;
		if (selection== "N" || selection == "n" || selection=="B" || selection=="b" || selection=="F" || selection=="f" 
		|| selection=="U" || selection=="u") //enter to create New file function.
		{
			enterFunction=1;
		}
		else if(selection== "D" || selection == "d" || selection== "O" || selection == "o" ||selection== "I" || selection == "i" || 
		selection=="C" || selection=="c" || selection=="P" || selection=="p" || selection=="x" || selection=="X")
		{
			if (file_name=="NULL") //user need to create a new file before Delete,Overwrite or Insert.
				{
					cout<<"Please create a new file first."<<endl;
					cout<<"* ============================================\n"<<endl;
					reselect=1;
					enterFunction=0;
				}
			else //enter to available fucntion(get NOT desired input).
			{
				tile_int=1;
				valid=false;
				while (!valid) //to check when input is NOT desired input(Not integer 1-8).
				{
					valid=true;
					if (selection=="C" || selection=="c" || selection=="X" ||selection=="x" ||
					selection=="D" ||selection=="d")
					{
						cout<<"From tile number==>";
					}
					else
					{
						cout<<"Tile number==>";
					}
					cin>>tile_int;
					cin.clear();
					cin.ignore(1000,'\n');
					if (cin.fail() || tile_int<1 || tile_int>80)//cin.fail() checks if the data types in the cin is true or false
					{
						cout<<"Please enter integer from 1 to 80 only."<<endl;
						valid=false;//The cin was not an integer from 1 to 8,so try again.		
					}
				}
				enterFunction=1;
			}
		}
		else if(selection == "L" || selection=="l") //Load function to read file
		{
			string output;
			string loadfilename;
			int numstring=0;
			int co=1;
			ifstream showfile;
			cout<<"File name==>";
			cin>>loadfilename;
			showfile.open(loadfilename.c_str());
			if(showfile.is_open())
			{
				while(!showfile.eof())
				{
					showfile>>output;
					text[co++]=output;
					numstring++;
				}
				for(int counter=numstring;counter<80;counter++)
				{
					text[counter]=" ";
				}
				showfile.close();
			}
			else
			{
				cout<<"The file does not exists.";
			}
			showfile.close();
			enterFunction=1;
		}
		else if (selection == "Q" || selection == "q") //Quit function to terminate the porgram.
		{
			return 0;
		}
		else if(selection == "S" || selection=="s")//Save function to save file.
		{
			ofstream outfile;
			string savefilename;
			cout<<"File name(enter [R]emain="<<file_name<<")==>";
			cin>>savefilename;
			if(savefilename=="R" || savefilename=="r")
			{
				savefilename=file_name;
			}
			else
			{
				file_name=savefilename;
			}
			outfile.open(file_name.c_str());
			cout<<"File saved."<<endl<<endl;
			cout<<"-----------------------"<<file_name<<" for reference"<<"---------------------------"<<endl;
			for(int n=1;text[n]!="";++n) // Display saved input.
			{
				outfile<<text[n]<<" ";
				cout<<text[n]<<" ";
			}
			cout<<endl<<endl;
			outfile.close();
		}
		else //direct back to reselect available selection when user enter undesired input. 
		{
			getline(cin,selection);
			cout<<"Not available selection.Please enter again."<<endl;
			cout<<"* ============================================\n"<<endl;
			reselect=1;
			enterFunction=0;
		}
		
//------------------------------------------------------------------------------------------------------------------------------------
	
		while ( enterFunction == 1) //while loop to enter available function.
		{
			if (selection== "N" || selection == "n") // New function to create new file
			{
				cout<< "New file name ==>";
				cin.ignore(); //ignore \n that lefted if user press enter key.
				getline(cin,file_name); //all file name altough with spaces and symbols or start with numbers will be accepted. 
				for (int tile_int=1;tile_int<81;tile_int++) //upon new first is created,there is no input in the block to be input-ed.
				{
					text[tile_int]=" ";
				}
			}
			enterFunction=0;;
			
			if 	(selection== "I" || selection == "i") //Insert function to insert input
			{
				if(tile_int<81) //implement when user enter integer from 1 to 80.
				{
					if(text[(tile_int-1)]==" " && tile_int !=1 ) //to check whether user enter the input accordingly or not.
					{
						cout<<"You must enter the input accordingly.";
						tile_int=-1;
					}
					else //if user follow the order,the initial input for particular tile number and the input after it, will be moved one step behind.
					{
						int countertile_int=tile_int;
						int stringnum=0;
						string tem_array[90];
						cout<<"Text==>";
						getline(cin,temporaly);//store input in a line
						for (int counter=1;counter<=80;counter++)//store inputfor undo
						{
							undo[counter]=text[counter];
						}
						for(int counter=1;counter<80;counter++) // store old input at temporaly array
						{
							tem_array[counter]=text[counter];	
						}		
						stringstream ss(temporaly);//new input
						cal_num_input=temporaly;	
						if (countertile_int<=countertile_int+10) //split and calculate the number of new input
						{
							while(getline(ss,word,' ') && countertile_int<=countertile_int+10)
							{
								stringnum++;
							}
						}
						if (stringnum>10) //number of input that exceed 10 is unaccepted.
						{
							cout<<"You can only insert at most 10 input at once!"<<endl;	
							stringnum=0;
							enterFunction=0;
							reselect=1;
						}
						else if(stringnum<=10) //store new input as text
						{
							stringstream ss(cal_num_input);
							while(getline(ss,cal_num_input,' ') && countertile_int<=countertile_int+10)
							{
								text[countertile_int++]=cal_num_input;
							}
						}
							
						for(int counter=80;counter>=tile_int;counter--) //add in new input & switch old input
						{
							int switching=counter+stringnum;
							text[switching]=tem_array[counter];
							tem_array[counter]="";
						}
					}
				}
				findtext="FindTextEmpty";
			}
			
			if 	(selection== "O" || selection == "o") //Overwrite function when input is from 1 to 80.
			{
				if(tile_int<81)
				{
					if (text[tile_int]==" ") //Overwrite only applied for input-ed block
					{
						cout<<"This block had no input.";
						tile_int=-1; //for not entering to build the table.
					}
					else
					{
						for (int counter=1;counter<=80;counter++)//for undo
						{
							undo[counter]=text[counter];
						}
						int stringnum=0;//calculate the number of string
						cout<<"Text==>";
						getline(cin,temporaly);//get new input in a line
						stringstream ss(temporaly);
						stext=temporaly; 
						int cal=tile_int;
						if (cal<=cal+10)
						{
							while(getline(ss,word,' ') && cal<=cal+10)
							{
								stringnum++; //calculate number of string;
							}
						}
						if (stringnum>10) //Maximum is 10,if exceed ,not accepted.
						{
							cout<<"You can only overwrite 10 text at once!";	
							stringnum=0;
							enterFunction=0;
							reselect=1;
						}
						else if(stringnum<=10)
						{
							stringstream ss(stext); //split new input
							while(getline(ss,stext,' ') && cal<=cal+10)
							{
								text[cal++]=stext;//store new input as text
							}
						}
						
					}
				}
				findtext="FindTextEmpty";
			}
			
			if 	(selection== "D" || selection == "d") //implement Delete function when input is from 1 to 80.
			{
				if(tile_int>=1 && tile_int<80)
				{
					if (text[tile_int]==" ") //Delete only applied for input-ed block
					{
						cout<<"This block had no input.";
						tile_int=-1; //for not entering to build the table.
					}
					else //the initial input for particular tile number and the input after it, will be moved one step in front.
					{
						for (int counter=1;counter<=80;counter++)//for undo
						{
							undo[counter]=text[counter];
						}
						int del; //del=delete
						int diff; //diff=different
						cout<<"To tile number==>";
						cin>>del;
						diff=del-tile_int+1;
						if (diff>10) //Only delete 1 to 10 input per time.
						{
							cout<<"You can only delete 10 text at once!";
							enterFunction=0;
							reselect=1;
						}
						else
						{
							for(int count=tile_int;count<=80;count++)
							{
								int hey=count+diff;
								text[count]=text[hey];
							}
						}
					}

				}
				findtext="FindTextEmpty";
			}
			
			if 	(selection== "F" || selection == "f") //implement find function when input is from 1 to 80.
			{
				cout<<"Enter text to find==>"; //method is between the construction of table
				cin>> findtext;
			}
			
			if (selection == "c" || selection=="C")// Copy function to copy text.
			{
				if(tile_int>=1 && tile_int<81)
				{
					if (text[tile_int]==" ") //Copy only applied for input-ed block
					{
						cout<<"This block had no input.";
						tile_int=-1; //for not entering to build the table.
					}
					else //the initial input for particular tile number and the input after it, will be moved one step in front.
					{
						for (int counter=1;counter<=80;counter++) //for undo
						{
							undo[counter]=text[counter];
						}
						int copyto;
						int diff;
						int numcopy=0;
						cout<<"To tile number==>";
						cin>>copyto;
						textcopy="";
						for(int count=tile_int;count<=copyto;count++) //copy the text in textcopy
						{
							textcopy=textcopy+text[count]+" ";
							numcopy++;
						}
					}
				}
				findtext="FindTextEmpty";
			}
			
			if(selection=="B" ||selection=="b")//clipboard to display copied /cut text.
			{
				cout<<"Clipboard:";
				cout<<textcopy<<endl;
				findtext="FindTextEmpty";
			}

			if (selection == "X" || selection=="x")//Cut function 
			{
				if(tile_int>=1 && tile_int<81)
				{
					if (text[tile_int]==" ") //Cut only applied for input-ed block
					{
						cout<<"This block had no input.";
						tile_int=-1; //for not entering to build the table.
					}
					else //the initial input for particular tile number and the input after it, will be moved one step in front.
					{
						for (int counter=1;counter<=80;counter++)//for undo
						{
							undo[counter]=text[counter];
						}
						int del;
						int diff;
						cout<<"To tile number==>";
						cin>>del;
						diff=del-tile_int+1;
						textcopy="";
						for(int count=tile_int;count<=del;count++)
						{
							textcopy=textcopy+text[count]+" ";
							copynum++;
						}
						for(int count=tile_int;count<80;count++)
						{
							int switching=count+diff;
							text[count]=text[switching];
						}
					}
				}
				findtext="FindTextEmpty";
			}
			
			if 	(selection== "P" || selection == "p") //implement Paste function
			{
				 if(tile_int<81) 
				{
					if(text[(tile_int-1)]==" " && tile_int !=1 ) //to check whether user enter the input accordingly or not.
					{
						cout<<"You must enter the input accordingly.";
						tile_int=-1;
					}
					else //if user follow the order,the initial input for particular tile number and the input after it, will be moved one step behind.
					{
						for (int c=1;c<=80;c++)//for undo
						{
							undo[c]=text[c];
						}
						int cal=tile_int;
						int stringnum=0;
						string tem_array[90];
						for(int counter=1;counter<80;counter++) // store old input at temporaly place
						{
							tem_array[counter]=text[counter];	 
						}
						stringstream ss(textcopy);
						if (cal<=cal+10) //split new input
						{
							while(getline(ss,newpaste,' ') && cal<=cal+10)
							{
								text[cal++]=newpaste;
								stringnum++;
							}
						}
						for(int counter=80;counter>=tile_int;counter--) //add in new input & switching
						{
							int switching=counter+stringnum;
							text[switching]=tem_array[counter];
							tem_array[counter]=" ";
						}
					}
				}
				findtext="FindTextEmpty";
			}
			
			if(selection=="U" || selection=="u")//Undo
			{
				for (int counter=1;counter<=80;counter++)
				{
					text[counter]=undo[counter];
				}
				findtext="FindTextEmpty";
			}
			
//-----------------------------------to construct the table----------------------------------------------------------------------------
			
			cout<<"\n------------------------ new screen ------------------\n"<<endl;
			cout<<"File name:"<<file_name<<endl;
			
			//to determine the row of table occur
			if (text[8]==" " && text[8].length()==1)
			{
				totalr=5;
			}
			else if (text[16]==" " &&text[16].length()==1)
			{
				totalr=7;
			}
			else if (text[24]==" " && text[24].length()==1)
			{
				totalr=9;
			}
			else if (text[32]==" "&& text[32].length()==1)
			{
				totalr=11;
			}
			else if (text[40]==" " && text[40].length()==1)
			{
				totalr=13;
			}
			else if (text[48]==" " && text[48].length()==1)
			{
				totalr=15;
			}
			else if (text[56]==" "&& text[56].length()==1)
			{
				totalr=17;
			}
			else if (text[64]==" " && text[64].length()==1)
			{
				totalr=19;
			}
			else if (text[72]==" " && text[72].length()==1)
			{
				totalr=21;
			}
			else if(text[80]==" " && text[80].length()==1)
			{
				totalr=23;
			}
			
			//to determine the length of table
			longestr4=0;
			for (int co=1;co<=73;co=co+8)
			{
				if(text[co].length()>=longestr4)
				{
					longestr4=text[co].length();
				}
			}
			longestr6=0;
			for (int co=2;co<=74;co=co+8)
			{
				if(text[co].length()>=longestr6)
				{
					longestr6=text[co].length();
				}
			}
			longestr8=0;
			for (int co=3;co<=75;co=co+8)
			{
				if(text[co].length()>=longestr8)
				{
					longestr8=text[co].length();
				}
			}
			longestr10=0;
			for (int co=4;co<=76;co=co+8)
			{
				if(text[co].length()>=longestr10)
				{
					longestr10=text[co].length();
				}
			}
			longestr12=0;
			for (int co=5;co<=77;co=co+8)
			{
				if(text[co].length()>=longestr12)
				{
					longestr12=text[co].length();
				}
			}
			longestr14=0;
			for (int co=6;co<=78;co=co+8)
			{
				if(text[co].length()>=longestr14)
				{
					longestr14=text[co].length();
				}
			}
			longestr16=0;
			for (int co=7;co<=79;co=co+8)
			{
				if(text[co].length()>=longestr16)
				{
					longestr16=text[co].length();
				}
			}
			longestr18=0;
			for (int co=8;co<=80;co=co+8)
			{
				if(text[co].length()>=longestr18)
				{
					longestr18=text[co].length();
				}
			}
			for (r=1;r<=totalr;++r) 
			{
				for (column=1;column<=19;++column)
				{
					if(r%2==1)
					{
						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{	
							cout<<"----";
						} 
						else if(column==4)
							{		
								for (text_length=1;text_length<(longestr4+3);++text_length)
								{
									cout<<"-";
								}
									
							}
							else if (column==6)
							{
								for (text_length=1;text_length<(longestr6+3);++text_length)
								{
									cout<<"-";
								}
								
							}
							else if (column==8)
							{
								for (text_length=1;text_length<(longestr8+3);++text_length)
								{
									cout<<"-";
								}
								
							}
							else if (column==10)
							{
								for (text_length=1;text_length<(longestr10+3);++text_length)
								{
									cout<<"-";
								}
									
							}
							else if (column==12)
							{
								for (text_length=1;text_length<(longestr12+3);++text_length)
								{
									cout<<"-";
								}
									
							}
							else if (column==14)
							{
								for (text_length=1;text_length<(longestr14+3);++text_length)
								{
									cout<<"-";
								}
									
							}
							else if (column==16)
							{
								for (text_length=1;text_length<(longestr16+3);++text_length)
								{
									cout<<"-";
								}	
							}
							else if (column==18)
							{
								for (text_length=1;text_length<(longestr18+3);++text_length)
								{
									cout<<"-";
								}	
							}
						
						else if (column==3||column==5||column==7||column==9||column==11||column==13||column==15||column==17)
						{
							cout<<"+";
						}
					}
					else if(r==2)
					{
						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{		
							cout<<"    ";
						}
						else if(column%2==1)
						{
							cout<<"|";	
						}
						else if(num<=9)
						{
							
							if(column==4)
							{		
								if (longestr4== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr4+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==6)
							{
								if (longestr6== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr6+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==8)
							{
								if (longestr8== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr8+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==10)
							{
								if (longestr10== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr10+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==12)
							{
								if (longestr12== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr12+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==14)
							{
								if (longestr14== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr14+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==16)
							{
								if (longestr16== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr16+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							else if (column==18)
							{
								if (longestr18== 0)
								{
									cout<<"  ";
								}
								else
								{
									for (text_length=1;text_length<(longestr18+2);++text_length)
									{
										cout<<" ";
									}
								}	
							}
							cout<<num;
							num++;
							if(num>=9)
							{
								num=1;
							}
						}
					}
					else if(r==4)
					{
						for(int co=1;co<=8;co++)
						{
							while(text[co]==findtext && column==co*2+3)
							{
								cout<<"=";
								column++;
							}
						}
						if(column==2)
						{
							if(r==4)
							{
								cout<<" 00 ";
							}
						}
						else if(column==4)
						{	
							if (text[1].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[1]<<" ";
								for(int co=text[1].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (r==4 && column==6)
						{
							if (text[2].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[2]<<" ";
								for(int co=text[2].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[3].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[3]<<" ";
								for(int co=text[3].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[4].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[4]<<" ";
								for(int co=text[4].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
								
							}
						}
						else if (column==12)
						{
							if (text[5].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[5]<<" ";
								for(int co=text[5].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[6].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[6]<<" ";	
								for(int co=text[6].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[7].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[7]<<" ";	
								for(int co=text[7].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[8]==" ")
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[8]<<" ";
								for(int co=text[8].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}	
						}
						else
						{			
							cout<<"|";
						}
					
					}
					else if(r==6)
					{
						for(int co=9;co<=16;co++)
						{
							while(text[co]==findtext && column==(co-8)*2+3)
							{
								cout<<"=";
								column++;
							}
						}
						if(column==2)
						{
							if(r==6)
							{
								cout<<" 08 ";
							}
						}
						else if(column==4)
						{	
							if (text[9].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[9]<<" ";
								for(int co=text[9].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[10].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[10]<<" ";
								for(int co=text[10].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[11].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[11]<<" ";	
								for(int co=text[11].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[12].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[12]<<" ";	
								for(int co=text[12].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[13].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[13]<<" ";	
								for(int co=text[13].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[14].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[14]<<" ";	
								for(int co=text[14].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[15].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[15]<<" ";
								for(int co=text[15].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[16].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[16]<<" ";	
								for(int co=text[16].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==8)
					{
						for(int co=17;co<=24;co++)
						{
							while(text[co]==findtext && column==(co-16)*2+3)
							{
								cout<<"=";
								column++;
							}
						}
						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==8)
							{
								cout<<" 16 ";
							}
						}
						else if(column==4)
						{	
							if (text[17].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[17]<<" ";	
								for(int co=text[17].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[18].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[18]<<" ";	
								for(int co=text[18].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[19].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[19]<<" ";	
								for(int co=text[19].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[20].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[20]<<" ";	
								for(int co=text[20].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[21].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[21]<<" ";	
								for(int co=text[21].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[22].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[22]<<" ";
								for(int co=text[22].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[23].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[23]<<" ";
								for(int co=text[23].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[24].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[24]<<" ";	
								for(int co=text[24].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==10)
					{
						for(int co=25;co<=32;co++)
						{
							while(text[co]==findtext && column==(co-24)*2+3)
							{
								cout<<"=";
								column++;
							}
						}

						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==10)
							{
								cout<<" 24 ";
							}
						}
						else if(column==4)
						{	
							if (text[25].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[25]<<" ";	
								for(int co=text[25].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[26].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[26]<<" ";	
								for(int co=text[26].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[27].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[27]<<" ";	
								for(int co=text[27].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[28].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[28]<<" ";	
								for(int co=text[28].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[29].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[29]<<" ";
								for(int co=text[29].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[30].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[30]<<" ";
								for(int co=text[30].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[31].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[31]<<" ";
								for(int co=text[31].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[32].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[32]<<" ";
								for(int co=text[32].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==12)
					{
						for(int co=33;co<=40;co++)
						{
							while(text[co]==findtext && column==(co-32)*2+3)
							{
								cout<<"=";
								column++;
							}
						}

						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==12)
							{
								cout<<" 32 ";
							}
						}
						else if(column==4)
						{	
							if (text[33].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[33]<<" ";
								for(int co=text[33].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[34].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[34]<<" ";
								for(int co=text[34].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[35].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[35]<<" ";	
								for(int co=text[35].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[36].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[36]<<" ";
								for(int co=text[36].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[37].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[37]<<" ";	
								for(int co=text[37].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[38].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[38]<<" ";
								for(int co=text[38].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[39].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[39]<<" ";
								for(int co=text[39].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[40].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[40]<<" ";	
								for(int co=text[40].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==14)
					{
						for(int co=41;co<=48;co++)
						{
							while(text[co]==findtext && column==(co-40)*2+3)
							{
								cout<<"=";
								column++;
							}
						}

						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==14)
							{
								cout<<" 40 ";
							}
						}
						else if(column==4)
						{	
							if (text[41].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[41]<<" ";	
								for(int co=text[41].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[42].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[42]<<" ";
								for(int co=text[42].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[43].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[43]<<" ";
								for(int co=text[43].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[44].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[44]<<" ";	
								for(int co=text[44].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[45].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[45]<<" ";	
								for(int co=text[45].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[46].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[46]<<" ";
								for(int co=text[46].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[47].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[47]<<" ";	
								for(int co=text[47].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[48].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[48]<<" ";	
								for(int co=text[48].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==16)
					{
						for(int co=49;co<=56;co++)
						{
							while(text[co]==findtext && column==(co-48)*2+3)
							{
								cout<<"=";
								column++;
							}
						}

						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==16)
							{
								cout<<" 48 ";
							}
						}
						else if(column==4)
						{	
							if (text[49].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[49]<<" ";
								for(int co=text[49].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[50].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[50]<<" ";	
								for(int co=text[50].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[51].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[51]<<" ";	
								for(int co=text[51].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[52].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[52]<<" ";	
								for(int co=text[52].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[53].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[53]<<" ";	
								for(int co=text[53].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[54].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[54]<<" ";	
								for(int co=text[54].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[55].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[55]<<" ";	
								for(int co=text[55].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[56].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[56]<<" ";	
								for(int co=text[56].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==18)
					{
						for(int co=57;co<=64;co++)
						{
							while(text[co]==findtext && column==(co-56)*2+3)
							{
								cout<<"=";
								column++;
							}
						}
						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==18)
							{
								cout<<" 56 ";
							}
						}
						else if(column==4)
						{	
							if (text[57].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[57]<<" ";	
								for(int co=text[57].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[58].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[58]<<" ";	
								for(int co=text[58].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[59].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[59]<<" ";	
								for(int co=text[59].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[60].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[60]<<" ";	
								for(int co=text[60].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[61].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[61]<<" ";	
								for(int co=text[61].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[62].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[62]<<" ";	
								for(int co=text[62].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[63].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[63]<<" ";	
								for(int co=text[63].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[64].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[64]<<" ";	
								for(int co=text[64].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==20)
					{
						for(int co=65;co<=72;co++)
						{
							while(text[co]==findtext && column==(co-64)*2+3)
							{
								cout<<"=";
								column++;
							}
						}

						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==20)
							{
								cout<<" 64 ";
							}
						}
						else if(column==4)
						{	
							if (text[65].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[65]<<" ";	
								for(int co=text[65].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[66].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[66]<<" ";
								for(int co=text[66].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
								
							}
						}
						else if (column==8)
						{
							if (text[67].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[67]<<" ";	
								for(int co=text[67].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[68].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[68]<<" ";	
								for(int co=text[68].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[69].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[69]<<" ";
								for(int co=text[69].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
								
							}
						}
						else if (column==14)
						{
							if (text[70].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[70]<<" ";	
								for(int co=text[70].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[71].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[71]<<" ";	
								for(int co=text[71].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==18)
						{
							if (text[72].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[72]<<" ";	
								for(int co=text[72].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
					else if(r==22)
					{
						for(int co=73;co<=80;co++)
						{
							while(text[co]==findtext && column==(co-72)*2+3)
							{
								cout<<"=";
								column++;
							}
						}

						if (column==1 || column==19)
						{
							cout<<"|";
						}	
						else if(column==2)
						{
							if(r==22)
							{
								cout<<" 72 ";
							}
						}
						else if(column==4)
						{	
							if (text[73].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[73]<<" ";	
								for(int co=text[73].length()+1;co<=longestr4;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==6)
						{
							if (text[74].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[74]<<" ";	
								for(int co=text[74].length()+1;co<=longestr6;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==8)
						{
							if (text[75].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[75]<<" ";	
								for(int co=text[75].length()+1;co<=longestr8;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==10)
						{
							if (text[76].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[76]<<" ";	
								for(int co=text[76].length()+1;co<=longestr10;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==12)
						{
							if (text[77].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[77]<<" ";	
								for(int co=text[77].length()+1;co<=longestr12;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==14)
						{
							if (text[78].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[78]<<" ";	
								for(int co=text[78].length()+1;co<=longestr14;co++)
								{
									cout<<" ";
								}
							}
						}
						else if (column==16)
						{
							if (text[79].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[79]<<" ";
								for(int co=text[79].length()+1;co<=longestr16;co++)
								{
									cout<<" ";
								}
								
							}
						}
						else if (column==18)
						{
							if (text[80].length()==0)
							{
								cout<<"   ";
							}
							else
							{
								cout<<" "<<text[80]<<" ";	
								for(int co=text[80].length()+1;co<=longestr18;co++)
								{
									cout<<" ";
								}
							}
						}
						else
						{			
							cout<<"|";
						}
					}
				}
				column==1;
				cout<<"\n";
			}
			cout<<"\n";
		}
		reselect=1;
	}
}
#include <map>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <vector>
#include <conio.h>

using namespace std;

void ChangeCase(char word[])
{
  for(size_t i = 0; i < strlen(word); i++)
    { if( isupper(word[i])) word[i] = tolower(word[i]);}
}

float maxscore=0;
class feature
{
    string t1;
    double length;
    double senposi;
    double medterm;
    double accronyms;
	
public:
    
	void sentence(string p)
    {t1=p;
    //cout<<t1;
    }
    
	void sentencelength(double p)
    {
		length=p;
	}
    
	double sentenceposition(int p, int i)
    {
        double q;
        q=sqrt(p);
        //float i;
        senposi=(1/q);
        //senpos=i;
        cout<<senposi;
           return senposi;
    }
    
	double medterms() 
    {
	//------------------------------------------------------------------------------------------
    // NOTE: This is just a sample list of medical terms. One can get the complete list from any 
	// medical dictionaries available online and add all those words in a "if" condition.
	//------------------------------------------------------------------------------------------
	
    int p = 0;
    for (int i = 0; t1[i] != '\0'; i++) 
	{
      string t = "";
      for (int j = i; t1[j] != ' '; j++, i++)
         t = t + t1[j];
      if (t == "11-dehydrocorticosterone" || t == "1,2:5,6-dibenzanthracene" || t == "1,25-dihydroxycholecalciferol" || t == "1,3-diphosphoglyceric" || t == "17a-hydroxyprogesterone" || t == "17-hydroxycorticosteroid" || t == "abdominal" || t == "abdominale" || t == "astriction" || t == "astringe" || t == "astringencies" || t == "duodenoscope" || t == "gastroenterologies" || t == "hyposensitivity" || t == "liquescent" || t == "neurobiologist" || t == "pyrathiazine" || t == "rosaniline" ||  t == "synchondrotomy" || t == "traumatologist") 
	  {
        p++;
      }
	  
      medterm = (double) p;
    }
      cout << medterm;
      return medterm;
    }
	
    double noofaccronyms()
    {
        double p=0;
        for(int i=0;t1[i]!='\0';i++)
        {
                string t="";
                for(int j=i;t1[j]!=' ';j++,i++)
                        t=t+t1[j];
        if(t=="aaa" || t=="aas" || t=="abd" || t=="abg" || t=="ac" || t=="acls" || t=="acth" || t=="ad" || t=="adlib" || t=="adh" || t=="adl" || t=="af" || t=="afb" || t=="afp" || t=="afo" || t=="a/g" || t=="ai" || t=="aka" || t=="all" || t=="als" || t=="amb" || t=="aml" || t=="ana" || t=="aob" || t=="aodm" || t=="ap" || t=="ards" || t=="arf" || t=="as" || t=="asap" || t=="ascvd" || t=="asd" || t=="ashd" || t=="asia" || t=="av" || t=="a-v" || t=="a-vo2" || t=="bbb" || t=="bc" || t=="bcaa" || t=="be" || t=="bee" || t=="bid" || t=="bilat" || t=="bka" || t=="bm" || t=="bmr" || t=="bom" || t=="bp" || t=="bph" || t=="bpm" || t=="brbpr" || t=="brp" || t=="bs" || t=="bun" || t=="bw" || t=="bx" || t=="c" || t=="c&s" || t=="ca" || t=="ca" || t=="caa" || t=="cabg" || t=="cad" || t=="cat" || t=="cbc" || t=="cbg" || t=="cc" || t=="ccu" || t=="ccv" || t=="cf" || t=="cgl" || t=="chf" || t=="cho" || t=="ci" || t=="cml" || t=="cmv" || t=="cn" || t=="cns" || t=="co" || t=="c/o" || t=="cold" || t=="copd" || t=="cp" || t=="cpap" || t=="cpk" || t=="cpr" || t=="crcl" || t=="crf" || t=="crp" || t=="crts" || t=="csf" || t=="csw" || t=="ct" || t=="cva" || t=="cvat" || t=="cvp" || t=="cxr" || t=="dat" || t=="daw" || t=="dc" || t=="d&c" || t=="ddx" || t=="d5w" || t=="di" || t=="dic" || t=="dip" || t=="djd" || t=="dka" || t=="dl" || t=="dm" || t=="dna" || t=="dnr" || t=="doa" || t=="doe" || t=="dpl" || t=="dpt" || t=="dtr" || t=="dvt" || t=="dx" || t=="eaa" || t=="ebl" || t=="ecd" || t=="ecg" || t=="ect" || t=="ed" || t=="efad" || t=="emg" || t=="emv" || t=="ent" || t=="eom" || t=="esr" || t=="et" || t=="ett" || t=="ercp" || t=="etoh" || t=="eua" || t=="fbs" || t=="fes" || t=="fev" || t=="ffp" || t=="frc" || t=="ftt" || t=="fu" || t=="fuo" || t=="fvc" || t=="fx" || t=="gc" || t=="gett" || t=="gfr" || t=="gi" || t=="gr" || t=="gsw" || t=="gt" || t=="gtt" || t=="gtt" || t=="gu" || t=="gxt" || t=="ha" || t=="haa" || t=="hav" || t=="hbp" || t=="hcg" || t=="hct" || t=="hdl" || t=="heent" || t=="hgb" || t=="h/h" || t=="hiv" || t=="hla" || t=="hjr" || t=="ho" || t=="hob" || t=="hpf" || t=="hpi" || t=="hr" || t=="hs" || t=="hsm" || t=="htlv-iii" || t=="hsv" || t=="htn" || t=="hx" || t=="i&d" || t=="i&o" || t=="ics" || t=="icu" || t=="id" || t=="iddm" || t=="ig" || t=="ihss" || t=="im" || t=="imv" || t=="inf" || t=="ippb" || t=="irbbb" || t=="irdm" || t=="itp" || t=="iv" || t=="ivc" || t=="ivp" || t=="jodm" || t=="jvd" || t=="kafo" || t=="kor" || t=="kt" || t=="kub" || t=="kvo" || t=="l" || t=="lad" || t=="lae" || t=="lahb" || t=="lap" || t=="lbbb" || t=="ldh" || t=="ldl" || t=="le" || t=="lih" || t=="lll" || t=="lmp" || t=="lnmp" || t=="loc" || t=="lp" || t=="lpn" || t=="lul" || t=="lv" || t=="lvedp" || t=="lvh" || t=="mao" || t=="map" || t=="mast" || t=="mbt" || t=="mch" || t=="mchc" || t=="mcv" || t=="mi" || t=="ml" || t=="mle" || t=="mmef" || t=="mmol" || t=="mmr" || t=="mri" || t=="mrsa" || t=="ms" || t=="mssa" || t=="muse" || t=="mva" || t=="mvi" || t=="mvv" || t=="nad" || t=="nas" || t=="ncv" || t=="ned" || t=="ng" || t=="ng" || t=="niddm" || t=="nka" || t=="nkda" || t=="nmr" || t=="npo" || t=="nrm" || t=="nsaid" || t=="nsr" || t=="nt" || t=="ob" || t=="ocg" || t=="od" || t=="om" || t=="oob" || t=="opv" || t=="or" || t=="os" || t=="ot" || t=="ou" || t=="p" || t=="pa" || t=="pac" || t=="pao2" || t=="pao2" || t=="pap" || t=="pat" || t=="p&pd" || t=="pc" || t=="pcwp" || t=="pda" || t=="pdr" || t=="pe" || t=="peep" || t=="pft" || t=="pg" || t=="pi" || t=="pku" || t=="pmh" || t=="pmi" || t=="pmn" || t=="pnd" || t=="po" || t=="pod" || t=="pp" || t=="ppd" || t=="ppms" || t=="pps" || t=="pr" || t=="prbc" || t=="prn" || t=="ps" || t=="psa" || t=="pt" || t=="pt" || t=="ptca" || t=="pth" || t=="pthc" || t=="ptsd" || t=="ptt" || t=="pud" || t=="pvc" || t=="pvd" || t=="pvr" || t=="q" || t=="qd" || t=="qh" || t=="q4h" || t=="q6h" || t=="qid" || t=="qns" || t=="qod" || t=="qs" || t=="qt" || t=="r" || t=="ra" || t=="rad" || t=="rae" || t=="rap" || t=="rbbb" || t=="rbc" || t=="rbp" || t=="rda" || t=="rdw" || t=="ria" || t=="rih" || t=="rll" || t=="rlq" || t=="rml" || t=="rna" || t=="r/o" || t=="rom" || t=="ros" || t=="rpg" || t=="rpms" || t=="rrms" || t=="rrr" || t=="rt" || t=="rta" || t=="rtc" || t=="ru" || t=="rug" || t=="rul" || t=="ruq" || t=="rv" || t=="rvh" || t=="rx" || t=="s" || t=="sa" || t=="saa" || t=="s&e" || t=="sbe" || t=="sbft" || t=="sbs" || t=="scr" || t=="sci" || t=="sci/d" || t=="sem" || t=="sg" || t=="sga" || t=="sggt" || t=="sgot" || t=="sgpt" || t=="siadh" || t=="sig" || t=="simv" || t=="sl" || t=="sle" || t=="smo" || t=="soap" || t=="sob" || t=="spms" || t=="sq" || t=="ss" || t=="stat" || t=="svd" || t=="sw" || t=="sx" || t=="t&c" || t=="tah" || t=="t&h" || t=="tb" || t=="tbg" || t=="td" || t=="tia" || t=="tibc" || t=="tid" || t=="tig" || t=="tko" || t=="tlc" || t=="tmj" || t=="tntc" || t=="to" || t=="topv" || t=="tpn" || t=="tsh" || t=="tt" || t=="ttp" || t=="tu" || t=="tur" || t=="turbt" || t=="turp" || t=="tv" || t=="tvh" || t=="tw" || t=="tx" || t=="ua" || t=="uac" || t=="ud" || t=="ugi" || t=="uri" || t=="us" || t=="uti" || t=="uun" || t=="vc" || t=="vcug" || t=="vma" || t=="vo" || t=="v/q" || t=="vss" || t=="wb" || t=="wbc" || t=="wd" || t=="wf" || t=="wm" || t=="wn" || t=="wnl" || t=="wpw" || t=="xrt" || t=="yo" || t=="ze")
        {
			p++;
		}
          accronyms=p;
        }
        cout<<accronyms;
        return accronyms;
    //  cout<<p;
    }
    
	double score;
    
	double total()
    {
          if(score>maxscore)maxscore=score;
        score=(double)length+senposi+medterm+accronyms;
        return score;
    }
}*obj;

int main()
{
    fflush(stdin);
    int i=0,j=1;
    vector<string> sentences;
    vector<double> totallength;
    vector<int> senpos;
    vector<double> nmed;
    vector<double> nacc;
    vector<double> npos;
    vector<double> nlen;

    string temp="",maincount=".";
    ifstream example;
    example.open("example.txt");
    ofstream example1;
    example1.open("example1.txt");
    if(!example.is_open())
    {
        exit(EXIT_FAILURE);
    }
    char word[50];
    example>>word;
    while (example.good())
    {
          ChangeCase(word);
          i++;
if( std::strcmp(word, "a") != 0 && std::strcmp(word, "in") != 0 && std::strcmp(word, "able") != 0 &&std::strcmp(word, "about") != 0 &&std::strcmp(word, "across") != 0 &&std::strcmp(word, "after") != 0 &&std::strcmp(word, "all") != 0 &&std::strcmp(word, "almost") != 0 &&std::strcmp(word, "also") != 0 &&std::strcmp(word, "am") != 0 &&std::strcmp(word, "among") != 0 &&std::strcmp(word, "an") != 0 &&std::strcmp(word, "and") != 0 &&std::strcmp(word, "any") != 0 &&std::strcmp(word, "are") != 0 &&std::strcmp(word, "as") != 0 &&std::strcmp(word, "at") != 0 &&std::strcmp(word, "be") != 0 &&std::strcmp(word, "because") != 0 &&std::strcmp(word, "been") != 0 &&std::strcmp(word, "but") != 0 &&std::strcmp(word, "by") != 0 &&std::strcmp(word, "can") != 0 &&std::strcmp(word, "cannot") != 0 &&std::strcmp(word, "could") != 0 &&std::strcmp(word, "dear") != 0 &&std::strcmp(word, "did") != 0 &&std::strcmp(word, "do") != 0 &&std::strcmp(word, "dose") != 0 &&std::strcmp(word, "either") != 0 &&std::strcmp(word, "else") != 0 &&std::strcmp(word, "ever") != 0 &&std::strcmp(word, "every") != 0 &&std::strcmp(word, "for") != 0 &&std::strcmp(word, "from") != 0 &&std::strcmp(word, "get") != 0 &&std::strcmp(word, "got") != 0 &&std::strcmp(word, "had") != 0 &&std::strcmp(word, "has") != 0 &&std::strcmp(word, "have") != 0 &&std::strcmp(word, "he") != 0 &&std::strcmp(word, "her") != 0 &&std::strcmp(word, "hers") != 0 &&std::strcmp(word, "him") != 0 &&std::strcmp(word, "his") != 0 &&std::strcmp(word, "how") != 0 &&std::strcmp(word, "however") != 0 &&std::strcmp(word, "i") != 0 &&std::strcmp(word, "if") != 0 &&std::strcmp(word, "into") != 0 &&std::strcmp(word, "is") != 0 &&std::strcmp(word, "it") != 0 &&std::strcmp(word, "its") != 0 &&std::strcmp(word, "just") != 0 &&std::strcmp(word, "least") != 0 &&std::strcmp(word, "let") != 0 &&std::strcmp(word, "like") != 0 &&std::strcmp(word, "likely") != 0 &&std::strcmp(word, "may") != 0 &&std::strcmp(word, "me") != 0 &&std::strcmp(word, "might") != 0 &&std::strcmp(word, "most") != 0 &&std::strcmp(word, "must") != 0 &&std::strcmp(word, "my") != 0 &&std::strcmp(word, "neither") != 0 &&std::strcmp(word, "no") != 0 &&std::strcmp(word, "nor") != 0 &&std::strcmp(word, "not") != 0 &&std::strcmp(word, "of") != 0 &&std::strcmp(word,"?ff") != 0 &&std::strcmp(word, "often") != 0 &&std::strcmp(word, "since") != 0 &&std::strcmp(word, "so") != 0 &&std::strcmp(word, "some") != 0 &&std::strcmp(word, "than") != 0 &&std::strcmp(word, "that") != 0 &&std::strcmp(word, "the") != 0 &&std::strcmp(word, "their") != 0 &&std::strcmp(word, "them") != 0 &&std::strcmp(word, "then") != 0 &&std::strcmp(word, "the") != 0 &&std::strcmp(word, "there") != 0 &&std::strcmp(word, "these") != 0 &&std::strcmp(word, "they") != 0 &&std::strcmp(word, "this") != 0 &&std::strcmp(word, "tis") != 0 &&std::strcmp(word, "to") != 0 &&std::strcmp(word, "too") != 0 &&std::strcmp(word, "twas") != 0 &&std::strcmp(word, "us") != 0 &&std::strcmp(word, "wants") != 0 &&std::strcmp(word, "was") != 0 &&std::strcmp(word, "we") != 0 &&std::strcmp(word, "were") != 0 &&std::strcmp(word, "what") != 0 &&std::strcmp(word, "when") != 0 &&std::strcmp(word, "where") != 0 &&std::strcmp(word, "which") != 0 &&std::strcmp(word, "while") != 0 &&std::strcmp(word, "who") != 0 &&std::strcmp(word, "whom") != 0 &&std::strcmp(word, "why") != 0 &&std::strcmp(word, "will") != 0 &&std::strcmp(word, "with") != 0 &&std::strcmp(word, "would") != 0 &&std::strcmp(word, "yet") != 0 &&std::strcmp(word, "you") != 0 &&std::strcmp(word, "your") != 0 &&std::strcmp(word, "on") != 0 &&std::strcmp(word, "only") != 0 &&std::strcmp(word, "or") != 0 &&std::strcmp(word, "other") != 0 &&std::strcmp(word, "our") != 0 &&std::strcmp(word, "own") != 0 &&std::strcmp(word, "rether") != 0 &&std::strcmp(word, "said") != 0 &&std::strcmp(word, "say") != 0 &&std::strcmp(word, "says") != 0 &&std::strcmp(word, "she") != 0 &&std::strcmp(word, "should") != 0 &&std::strcmp(word, "whom") != 0 &&std::strcmp(word, "why") != 0 &&std::strcmp(word, "will") != 0 &&std::strcmp(word, "with") != 0 &&std::strcmp(word, "would") != 0 &&std::strcmp(word, "yet") != 0 &&std::strcmp(word, "you") != 0 &&std::strcmp(word, "your") != 0 )
{int c= strlen(word)-1;
cout<<word<<" ";
temp+=word;
temp+=" ";
if(word[c]=='.')
{
    temp[temp.size()-2]=' ';
    temp[temp.size()-1]='.';
    strcat(word,"\n");
    ostringstream oss;
    oss << i;
    maincount+= oss.str()+'.';
    //cout<<maincount;
    totallength.push_back(i);
    sentences.push_back(temp);
    senpos.push_back(j);
    temp="";
    i=0;
    j++;
}
example1<<word<<" ";
}
example>>word;
}
example1<<word<<" ";
cout<<word<<"   ";
int c= strlen(word)-1;
temp+=word;
temp+=" ";
if(word[c]=='.')
{
    temp[temp.size()-2]=' ';
    temp[temp.size()-1]='.';
    strcat(word,"\n");
    i++;
    ostringstream oss;
    oss << i;
    maincount+= oss.str();
    sentences.push_back(temp);
    //cout<<maincount;
    totallength.push_back(i);
    senpos.push_back(j);
    example1<<word<<" ";
    i=0;
}
example1<<word<<" ";
example.close();
cout<<"\nwriting............";
feature o;
obj=&o;
cout<<"\nObject declared............";
//cout<<"\nSentences.size\t"<<sentences.size();
double sscore;
vector<double> ntotal;
for(i=0;i<sentences.size();i++)
{

        obj->sentence(sentences[i]);
        cout<<"\n"<<sentences[i];
        obj->sentencelength(totallength[i]);
        cout<<"\ntotal length"<<totallength[i];
        cout<<"\n1 ";
        nmed.push_back(obj->medterms());
        cout<<"\n2 ";
        nacc.push_back(obj->noofaccronyms());
        cout<<"\n3 ";
        npos.push_back(obj->sentenceposition(senpos[i],i));
        cout<<"\n4 ";
        nlen.push_back(totallength[i]);
        sscore=obj->total();
        cout<<"\ni is "<<i;
        ntotal.push_back(obj->total());
}
cout<<"\nSScore generated............";

//cout<<"\n"<<"\n"<<senscore.size()<<"\n"<<"\n";
double maxi[5]={0.0};
for(i=0;i<sentences.size();i++)
{
    if(nmed[i]>maxi[1])maxi[1]=nmed[i];
    if(nacc[i]>maxi[2])maxi[2]=nacc[i];
    if(npos[i]>maxi[3])maxi[3]=npos[i];
    if(nlen[i]>maxi[4])maxi[4]=nlen[i];
}
cout<<"\nmaxi[1]\t:\t"<<maxi[1];
cout<<"\nmaxi[2]\t:\t"<<maxi[2];
cout<<"\nmaxi[3]\t:\t"<<maxi[3];
cout<<"\nmaxi[4]\t:\t"<<maxi[4];
cout<<"\nMaximum assigned............";

vector<double> finalscore;
double mnop;
for(i=0;i<sentences.size();i++)
{   mnop=0;
    if(maxi[1]!=0)
        mnop+=nmed[i]*4/maxi[1];
    if(maxi[2]!=0 )
        mnop+=nacc[i]*3/maxi[2];
    if(maxi[3]!=0 )
        mnop+=npos[i]*2/maxi[3];
    if(maxi[4]!=0 )
        mnop+=nlen[i]*1/maxi[4];
    finalscore.push_back(mnop);
        if(finalscore[i]>maxi[0])maxi[0]=finalscore[i];
}
cout<<"\nMaxi[0] : "<<maxi[0];
cout<<"\nMaximum assigned over............\n";
for(i=0;i<sentences.size();i++)
{
    finalscore[i]/=maxi[0];
    cout<<i<<" : finalscore "<<finalscore[i]<<"\n";
}
example1.close();
sentences.clear();
fstream example2;
example2.open("example.txt");
string s1="",s2="";
int k=0;
while(!example2.eof())
{
                      example2>>s1;
                      //cout<<s1;
                      if(s1[s1.size()-1]!='.')
                                 s2+=s1+" ";
                      else{ s2+=s1;
                      //cout<<s2<<endl<<"harsh1";
                      sentences.push_back(s2);k++;
                      cout<<sentences[k-1]<<endl;
                      s2="";
                      }
}
example2.close();
map<string,double> val;
map<string,double>::iterator iter;
map<double,string>::iterator iter1;
cout<<sentences.size();
for(int i=0;i<sentences.size();i++){val[sentences[i]]=finalscore[i];cout<<sentences[i]<<endl;}
cout<<sentences.size();
for(iter=val.begin();iter!=val.end();iter++)cout<<iter->first<<" "<<iter->second<<endl;
//sorting of map val using iter->second
map<double,string> val1;
for( iter=val.begin();iter!=val.end();iter++)
{
     val1[iter->second]=iter->first;
}
for( iter1=val1.begin();iter1!=val1.end();iter1++)
{
     cout<<iter1->first<<" "<<iter1->second<<endl;
}
//displaying 150 words
ofstream example3;
example3.open("example2.txt");
if(example3)example3.clear();
int c1=100;
cout<<"Enter No Of words in summary:";
cin>>c1;
std::map<double,string>::reverse_iterator rit;
//cout<<endl;cout<<endl;cout<<endl;
  for (rit=val1.rbegin(); rit!=val1.rend(); ++rit)
{
      for(int i=0;i<rit->second.size();i++)if(rit->second[i]==' ')c1-= 1;
      example3<<rit->second<<"\n";
     //cout<<endl<<rit->second;
     if(c1<=0)break;
}
example3.close();
system("PAUSE");
return 0;
}

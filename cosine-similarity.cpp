/*C++ program to show cosine similarities*/
#include<iostream>//include the library of input output stream
#include<fstream>//Header file for reading the word in the file
#include<vector>//Header file for storing the word in the documents
#include<map>//for relating the terms,frequencies,TF&TF_IDF and cosine smilarities
#include<cmath>//for  doing mathematical calculation
#include<algorithm>//for sorting
using namespace std;//allows us to use the standard library
void ChangeCase(string word)
{
  for(size_t i = 0; i < word.size(); i++)
    { if( isupper(word[i])) word[i] = tolower(word[i]);}
}
//string Lower(string& lowercase_term);//prototype for changing words to lowercase
void tf_idf_compute(map<string,float> &frequency,vector<vector<string> > &documents, vector<string> &terms);//prototype for finding a frequency of terms
int main()//where a c++ program starts/execution starts.
{//openining curled brac i.e main()opens
cout<<"Terms\t\tTerm frequency\t\t\tTF_IDF\t\tCosineSimilarity";
    cout<<"\n";
    vector<vector<string> > dc;// dictionary
    vector<string> tokens;//container for documents which represent refered vector  in prototype
    map<string,float>S;//A vector "s"that stores int type values.

    tf_idf_compute(S,dc,tokens);//call function for tf_idf
}
void tf_idf_compute(map<string,float> &frequency1,vector<vector<string> > &documents,vector<string> &terms)//function for creating a dictionery
{
     fstream file("example-1.txt");//opens the file named regs.
     map<string,float>::iterator iter;
     map<string,float> frequency2;map<string,float> frequency3;
     vector<string> words;
     float p=0,q=0,r=0;
       if(!file)// reading file is not found
       {
       cout<<"file not found"<<endl;
       }
       else
       {
         while(!file.eof())//reading file is not found doesnot mark end of fuction
         {
            string hb;//variable of type string for holding a term
            vector<string> fre;//container for storing terms before storing the terms into a memory
            while(file>>hb && hb!="#")//condition which direct raeding of documents with specified delimiter as the sign of an end of a document
            {
                    ChangeCase(hb);    //   if(hb==".")p++;
                   words.push_back(hb);//put terms into a temporary holding vector
                   terms.push_back(hb);//keep terms in memory
                    frequency1[hb]++;
                   sort(terms.begin(),terms.end());//sorting the terms
                   terms.erase(unique(terms.begin(),terms.end()),terms.end());//remove term repeatation
            }
            if(!words.empty())//if the vector is not empty
            {
            
                                documents.push_back(words);//push the words in temporary vector into the vector of vectors in order to be stored in a memory
            }
            words.clear();
            while(file>>hb && hb!="#")//condition which direct raeding of documents with specified delimiter as the sign of an end of a document
            {
                    ChangeCase(hb);      // if(hb==".")q++;
                   words.push_back(hb);//put terms into a temporary holding vector
                   terms.push_back(hb);//keep terms in memory
                    frequency2[hb]++;
                   sort(terms.begin(),terms.end());//sorting the terms
                   terms.erase(unique(terms.begin(),terms.end()),terms.end());//remove term repeatation
            }
            if(!words.empty())//if the vector is not empty
            {
                                documents.push_back(words);//push the words in temporary vector into the vector of vectors in order to be stored in a memory
            }
            words.clear();
            while(file>>hb && hb!="#")//condition which direct raeding of documents with specified delimiter as the sign of an end of a document
            {
                   ChangeCase(hb);        //if(hb==".")r++;
                   words.push_back(hb);//put terms into a temporary holding vector
                   terms.push_back(hb);//keep terms in memory
                    frequency3[hb]++;
                   sort(terms.begin(),terms.end());//sorting the terms
                   terms.erase(unique(terms.begin(),terms.end()),terms.end());//remove term repeatation
            }
            if(!words.empty())//if the vector is not empty
            {
            
                                documents.push_back(words);//push the words in temporary vector into the vector of vectors in order to be stored in a memory
            }

        }
        for(iter=frequency1.begin();iter!=frequency1.end();iter++)
        {
        p+=iter->second;
        }
        for(iter=frequency2.begin();iter!=frequency2.end();iter++)
        {
        q+=iter->second;
        }
        for(iter=frequency3.begin();iter!=frequency3.end();iter++)
        {
        r+=iter->second;
        }
        cout<<endl;
        for(iter=frequency1.begin();iter!=frequency1.end();iter++)
        {
        iter->second/=p;
         cout<<iter->first<<" "<<iter->second;
        }
        cout<<endl;
        for(iter=frequency2.begin();iter!=frequency2.end();iter++)
        {
        iter->second/=q;
         cout<<iter->first<<" "<<iter->second;
        }
        cout<<endl;
        for(iter=frequency3.begin();iter!=frequency3.end();iter++)
        {
         iter->second/=r;
         cout<<iter->first<<" "<<iter->second;
        }
        cout<<endl;
        int a;
        map<string,int> ting;
        for(int j=0;j<terms.size();j++)
        {
         a=0;
              //   cout<<terms[j]<<" ";
         for(int i=0;i<documents.size();i++)
         {
                 //finds if a term occurs or doesn't occcur in the document
                 for(int k=0;k<documents[i].size();k++)
                 {
                        // cout<<documents[i][k]<<endl;
                         if(documents[i][k]==terms[j]){a++;k=documents[i].size();}
                 }
         }
         ting[terms[j]]=a;
        //cout<<cnt<<endl;
        // cout<<endl<<endl;
        }
        //for(iter=ting.begin();iter!=ting.end();iter++)cout<<iter->first<<" "<<iter->second<<endl;
        //  for(int i=0;i<terms.size();i++)cout<<terms[i]<<" ";
        //operation for calculating tf_idf 
        int p=0;
        float tf_idf;
        float cosine;
        for(iter=frequency1.begin();iter!=frequency1.end();iter++)
        {
        tf_idf=(1+log10(iter->second))*log10(1+(documents.size()/ting[iter->first]));//formular to calculate tf_idf & cosine similarities
        cout<<iter->first<<"\t\t"<<iter->second<<"\t\t\t"<<tf_idf<<"\t\t"<<cosine<<endl;
        iter->second=tf_idf;
        }
        for(iter=frequency2.begin();iter!=frequency2.end();iter++)
        {
        tf_idf=(1+log10(iter->second))*(1+log10(documents.size()/ting[iter->first]));//formular to calculate tf_idf & cosine similarities
        cout<<iter->first<<"\t\t"<<iter->second<<"\t\t\t"<<tf_idf<<"\t\t"<<cosine<<endl;
        iter->second=tf_idf;
        }
        for(iter=frequency3.begin();iter!=frequency3.end();iter++)
        {
        tf_idf=(1+log10(iter->second))*(log10(documents.size()/ting[iter->first]+1));//formular to calculate tf_idf & cosine similarities
        cout<<iter->first<<"\t\t"<<iter->second<<"\t\t\t"<<tf_idf<<"\t\t"<<cosine<<endl;
        iter->second=tf_idf;
        }
        string s1;
        vector<float> sen1,sen2;
        //code for cosine calculation to be done
        //for first document
         words.clear();
         sen1.push_back(1);
        for(int i=0;i<documents[0].size();i++)
        {
                if(documents[0][i]!=".")
                {
                      words.push_back(documents[0][i]);
                }
                else
                {
                    float a=0.0,b=0.0,c=0.0,d=0.0;
                    for(int j=0;j<words.size();j++)
                    {
                            a+=frequency1[words[j]]*frequency2[words[j]];
                            b+=frequency1[words[j]]*frequency1[words[j]];
                            c+=frequency2[words[j]]*frequency2[words[j]];
                            //d+=frequency3[words[i]]*frequency3[words[i]];
                            //cout<<a<<" "<<b<<" "<<c<<" "<<endl;
                    }
                    sen1.push_back(a/(sqrt(b)*sqrt(c)));
                    words.clear();
                }
        }
        for(int i=0;i<documents[0].size();i++)
        {
                if(documents[0][i]!=".")
                {
                      words.push_back(documents[0][i]);
                }
                else
                {
                    float a=0.0,b=0.0,c=0.0,d=0.0;
                    for(int j=0;j<words.size();j++)
                    {
                            a+=frequency1[words[j]]*frequency3[words[j]];
                            b+=frequency1[words[j]]*frequency1[words[j]];
                            c+=frequency3[words[j]]*frequency3[words[j]];
                            //d+=frequency3[words[i]]*frequency3[words[i]];
                            //cout<<a<<" "<<b<<" "<<c<<" "<<endl;
                    }
                    sen1.push_back(a/(sqrt(b)*sqrt(c)));
                    words.clear();
                }
        }
        for(int i=0;i<sen1.size();i++)cout<<sen1[i]<<" ";
        //for second document
        for(int i=0;i<documents[1].size();i++)
        {
                if(documents[1][i]!="." )
                {
                      words.push_back(documents[1][i]);
                }
                else
                {
                    float a=0,b=0,c=0;
                    for(int j=0;j<words.size();j++)
                    {
                            a+=frequency1[words[j]]*frequency2[words[j]];
                            b+=frequency1[words[j]]*frequency1[words[j]];
                            c+=frequency2[words[j]]*frequency2[words[j]];
                    }
                    sen2.push_back(a/(sqrt(b)*sqrt(c)));
                    words.clear();
                }
        }
        sen2.push_back(1);
        for(int i=0;i<documents[1].size();i++)
        {
                if(documents[1][i]!="." )
                {
                      words.push_back(documents[1][i]);
                }
                else
                {
                    float a=0,b=0,c=0;
                    for(int j=0;j<words.size();j++)
                    {
                            a+=frequency3[words[j]]*frequency2[words[j]];
                            b+=frequency3[words[j]]*frequency3[words[j]];
                            c+=frequency2[words[j]]*frequency2[words[j]];
                    }
                    sen2.push_back(a/(sqrt(b)*sqrt(c)));
                    words.clear();
                }
        }
        for(int i=0;i<sen2.size();i++)cout<<sen2[i]<<" ";
       // for(int i=0;i<
        file.close();
        fstream file("example-1.txt");//opens the file named regs.
        string hb="",ss="";
        int j=0,k=0;//i no of ssentences j no of documents
        while(!file.eof())//reading file is not found doesnot mark end of fuction
        {
                                    file>>hb;
                                    ss+=hb+" ";
         }
        //cout<<documents.size();
        file.close();
        ofstream file1;
        file1.open("example-2.txt");
        hb="";
        for(int i=0;i<ss.length();i++)
        {//reading file is not found doesnot mark end of fuction
        if(ss[i]!='.')hb+=ss[i];
        else
        {
            cout<<endl<<hb;
            if(sen1[k++]>=-0.7 && j==0)file1<<hb<<". ";
            if(sen2[k++]>=-0.7 && j==1)file1<<hb<<". ";
            if(j==3)file1<<hb<<". ";
            if(hb=="#"){j++;k=0;}
            hb="";
        }
        }
        file1.close();
        cin.get();//holds the screen
        }
}//closing curled brac (}) i.e main()ends

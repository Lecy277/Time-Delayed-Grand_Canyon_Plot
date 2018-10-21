#include <iostream>
#include <list>
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>
#include "Q10.h"
using namespace std;
/// in other options, compiler settings -std=gnu++11
///only necessary if your C++ 11 does not find to_string
string to_string(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}
int main()
{
    /// declaring my lists
    string Triangle_file, Triangle_file2, Triangle_file3, Triangle_file4, Triangle_file5,Triangle_fileDyk, outfile;
    fstream fout, fout1, fout2, fout3, fout4, fout5, foutDyk;

    ///this cpp file will ZREXLTE the command file it will access.
    fout2.open("command.txt",ios::out);
    fout2<<"set view 65, 8,1.20,1.05"<<endl;
    fout2<<"set yrange [0:75]"<<endl;
    fout2<<"set xrange [0:75]"<<endl;
    fout2<<"set zrange [0:75]"<<endl;
    fout2<<"set xlabel \"RED Line Shows DIJKSTRA'S\""<<endl;
    fout2<<"set format y \"\" "<<endl;
    fout2<<"unset xtics"<<endl;
    fout2<<"unset ztics"<<endl;
    ///If you want to put the lines back into it so you can see the triangle's in the background just comment out "set hidden3d" and it will show the lines for the triangles.
    fout2<<"set hidden3d"<<endl;
    fout2<<"set border 4095 front linetype -1 linewidth 1.05"<<endl;
    fout2<<"set terminal pngcairo  transparent enhanced font \"arial,10\" fontscale 1.0 size 600, 400"<< endl;
    fout2<<"set cblabel \"color scale\" "<<endl;
    fout2<<"set pm3d implicit at s "<< endl;
    fout2<<"set palette defined ( 0 \"dark-blue\", 1 \"sienna4\",2 \"sienna4\", 3 \"sienna4\", 4 \"dark-green\")"<< endl;


    for(int y=1;y<20;y++)
    {
    Triangle_file="Triangles1"+to_string(y)+".dat";
    Triangle_file2="Triangles2"+to_string(y)+".dat";
    Triangle_file3="Triangles3"+to_string(y)+".dat";
    Triangle_file4="Triangles4"+to_string(y)+".dat";
    Triangle_file5="Triangles5" +to_string(y)+".dat";
    Triangle_fileDyk="TrianglesDyk.dat";
    outfile="Grand_Canyon_"+to_string(y)+".png";


    fout.open(Triangle_file.c_str(),ios::out);
    fout1.open(Triangle_file2.c_str(),ios::out);
    fout3.open(Triangle_file3.c_str(),ios::out);
    fout4.open(Triangle_file4.c_str(),ios::out);
    fout5.open(Triangle_file5.c_str(),ios::out);
    foutDyk.open(Triangle_fileDyk.c_str(),ios::out);
    fout2<<"set output \'"<<outfile<<"\'"<<endl;

    default_random_engine gen(time(NULL));
    list<int>The_Triangle, The_Triangle_RiverX, The_Triangle_RiverY, The_Triangle_RiverZ, The_Triangle_Bank;
    list<int>::iterator tritr, tritr1, tritr2, tritr3, tritr4, tritr5, tritr6, tritrXL, tritrXR, tritrY, tritrZL, tritrZR;
    int tritrCentX, tritrCentY;
    Triangle T;
    int x=0;
    int j=1;
    int z=1;
    int xx=0;
    int xxx=0;
    int dyx=100;
    int dyy=100;
    int riv=0;
    int riv1=0;

    ///start for loop for loading lists for left upper tier
    for (int m=0;m<6;m++)
    {
        The_Triangle.push_back(T.XL());
        The_Triangle.push_back(T.XL()+15.00*m);
        The_Triangle.push_back(x=gen()%3+12);
        The_Triangle.push_back(T.YL()+15.00*j);
        The_Triangle.push_back(T.Z());
        The_Triangle.push_back(T.XL2());

    if (m<5)
    {
        for(int t=0;t<4;t++)
        {   tritr=The_Triangle.begin();
            tritr1=The_Triangle.begin();
            advance (tritr1,1);
            tritr2=The_Triangle.begin();
            advance (tritr2,2);
            tritr3=The_Triangle.begin();
            advance (tritr3,3);
            tritr4=The_Triangle.begin();
            advance (tritr4,4);
            tritrCentY=(*tritr1+*tritr3*2)/3;
            tritrCentX=(*tritr+*tritr2)/3;
            ///version of dijkstra's algorithm to find shortest path for upper tier
           if (m<2&&t<1){
                if (m<2){foutDyk << ' ' << *tritr<< ' ' << *tritr1<<' '<<*tritr4<<endl;}
                if (dyx>=tritrCentX){dyx=tritrCentX; foutDyk<< ' '<<dyx;}
                if (dyy>=tritrCentY){dyy=tritrCentY;}
                else if (dyy<=tritrCentY){dyy=dyy;}
                foutDyk<< ' '<<dyy<<' '<<*tritr4<<endl;
              if(m==0){foutDyk << ' ' << *tritr1<< ' ' << *tritr3<<' '<<*tritr4<<endl;}
               else {foutDyk << ' ' << *tritr1<< ' ' << *tritr1<<' '<<*tritr4<<endl;}
                foutDyk << ' ' << *tritr<< ' ' << *tritr1<<' '<<*tritr4<<endl<<endl<<endl;
                dyx=100;}
            if(t==0||t==3)
            {fout << ' ' << *tritr<< ' ' << *tritr1;}
            if(t==1)
            {fout << ' ' << *tritr2<< ' ' << *tritr3;}
            if(t==2)
            {fout << ' ' << *tritr<< ' ' << *tritr3;}
            fout << ' ' << *tritr4<<endl;
            ///Refinement of triangles
            if (t==3)
            {///center refinement
            fout<<endl<< ' ' << tritrCentX<< ' ' << tritrCentY<<' ' <<*tritr4<<endl;
            fout<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr4<<endl;
            fout<<endl<< ' ' << tritrCentX<< ' ' << tritrCentY<<' ' <<*tritr4<<endl;
            fout<< ' ' << *tritr2<< ' ' << *tritr3<<' ' <<*tritr4<<endl;
            fout<<endl<< ' ' << tritrCentX<< ' ' << tritrCentY<<' ' <<*tritr4<<endl;
            fout<< ' ' << *tritr<< ' ' << *tritr3<<' ' <<*tritr4<<endl;

            ///edge refinement
            fout<<endl<< ' ' << *tritr+15<< ' ' << *tritr1<<' ' <<*tritr4<<endl;
            fout<< ' ' << tritrCentX<<' ' <<tritrCentY<<' ' <<*tritr4<<endl;
            fout << ' ' << *tritr2<< ' ' << *tritr3<<' ' <<*tritr4<<endl;
            fout << ' ' << *tritr+15<< ' ' << *tritr1<<' ' <<*tritr4<<endl;}
        }
    }
    if (m>4)
    {   tritr5=The_Triangle.begin();
        advance (tritr5,5);
        fout << ' ' << "0" << ' ' << *tritr4<< ' ' << *tritr4<<endl;
        fout << ' ' << *tritr5<< ' ' << *tritr4<< ' ' << *tritr4<<endl<<endl;
        fout << ' ' << "0"<< ' ' << "0"<< ' ' << *tritr4<<endl;
        fout << ' ' << *tritr5<< ' ' << "0"<< ' ' << *tritr4<<endl;}
        fout<<endl;
        The_Triangle.clear();
        j++;
    }
    fout.close();

    j=1;
    for (int m=0;m<5;m++)
    {///start for loop for loading lists for left lower tier
        The_Triangle.push_back(T.XL2());
        The_Triangle.push_back(T.YL2()+15.00*m);
        The_Triangle.push_back(xx=38-(y/2));
        The_Triangle.push_back(T.YLL2()*j);
        The_Triangle.push_back(T.Z2());
        The_Triangle.push_back(x=78-(4*y));

        for(int t=0;t<4;t++)
        {   tritr=The_Triangle.begin();
            tritr1=The_Triangle.begin();
            advance (tritr1,1);
            tritr2=The_Triangle.begin();
            advance (tritr2,2);
            tritr3=The_Triangle.begin();
            advance (tritr3,3);
            tritr4=The_Triangle.begin();
            advance (tritr4,4);
            tritr5=The_Triangle.begin();
            advance (tritr5,5);
            tritrCentX=(*tritr+*tritr2)/2;
            tritrCentY=(*tritr1+*tritr3)/2;
            ///version of dijkstra's algorithm to find shortest path for lower tier
            if (m==1&&t ==1){
                dyx=100; dyy=100;
                foutDyk << ' ' << *tritr<< ' ' << *tritr<<' '<<*tritr4<<endl;
                if (dyx>=tritrCentX){dyx=tritrCentX;foutDyk<< ' '<<dyx;}
                if (dyy>=tritrCentY){dyy=tritrCentY;}
                else if (dyy<=tritrCentY){dyy=dyy;}
                foutDyk<< ' '<<dyy<<' '<<*tritr5<<endl;
                foutDyk << ' ' << *tritr2<< ' ' << *tritr3<<' '<<*tritr5<<endl;
                foutDyk << ' ' << *tritr<< ' ' << *tritr<<' '<<*tritr4<<endl<<endl;}
            if(t==1)
            {fout3 << ' ' << *tritr2<< ' ' << *tritr3<< ' ' << *tritr5;}
            else{
            if(t==0||t==3)
            {fout3 << ' ' << *tritr<< ' ' << *tritr1;}
            if(t==2)
            {fout3 << ' ' << *tritr<< ' ' << *tritr3;}
             fout3 << ' ' << *tritr4;}
             fout3<<endl;
           ///Refinement of triangles edge refinement for river banks
            if (t==3)
            {fout3<<endl<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr4<<endl;
            fout3<< ' ' << tritrCentX<<' ' <<tritrCentY<<' ' <<*tritr5<<endl;
            fout3<< ' ' << *tritr2<< ' ' << *tritr3<<' ' <<*tritr5<<endl;
            fout3<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr4<<endl;

            if (t==3&&m==0)
            {The_Triangle_Bank.push_back(tritrCentX);
            The_Triangle_Bank.push_back(tritrCentY);
            The_Triangle_Bank.push_back(*tritr5);
            The_Triangle_RiverX.push_back(tritrCentX);
            The_Triangle_RiverY.push_back(tritrCentY);
            The_Triangle_RiverZ.push_back(*tritr5);}}
        }
        The_Triangle_Bank.push_back(*tritr2);
        The_Triangle_Bank.push_back(*tritr3);
        The_Triangle_Bank.push_back(*tritr5);
        The_Triangle_RiverX.push_back(*tritr2);
        The_Triangle_RiverZ.push_back(*tritr5);
        fout3<<endl;
        The_Triangle.clear();
        j++;

    }
    ///loop to fill in the gaps for the river
    for(int w=0; w<2; w++)
        {tritr=The_Triangle_Bank.begin();
        tritr1=The_Triangle_Bank.begin();
        tritr2=The_Triangle_Bank.begin();
        advance (tritr1,1); advance (tritr2,2);
        fout3<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl;
        advance (tritr,3); advance (tritr1,3);  advance (tritr2,3);
        fout3<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl;
        advance (tritr,3); advance (tritr1,3);  advance (tritr2,3);
        fout3<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl;
        tritr=The_Triangle_Bank.begin();
        tritr1=The_Triangle_Bank.begin();
        tritr2=The_Triangle_Bank.begin();
        advance (tritr1,1); advance (tritr2,2);
        fout3<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl<<endl;
        for(int w=0; w<9; w++){The_Triangle_Bank.pop_front();}}
    The_Triangle_Bank.clear();
    fout3.close();

     ///start for loop for loading lists for right upper tier
    for (int m=0;m<6;m++)
        {The_Triangle.push_back(T.XR());
        The_Triangle.push_back(T.YR()+15.00*m);
        The_Triangle.push_back(x=gen()%5+60);
        The_Triangle.push_back(T.YR()+15.00*z);
        The_Triangle.push_back(T.RZ());
        The_Triangle.push_back(T.YR2());
        The_Triangle.push_back(T.XR2());

    if (m<5)
        {
        for(int t=0;t<4;t++)
        {   tritr=The_Triangle.begin();
            tritr1=The_Triangle.begin();
            advance (tritr1,1);
            tritr2=The_Triangle.begin();
            advance (tritr2,2);
            tritr3=The_Triangle.begin();
            advance (tritr3,3);
            tritr4=The_Triangle.begin();
            advance (tritr4,4);
            tritr6=The_Triangle.begin();
            advance (tritr6,6);
            tritrCentY=(*tritr1+*tritr3*2)/3;
            tritrCentX=(*tritr*2+*tritr2)/3;
            if(t==0||t==3)
            {fout1 << ' ' << *tritr<< ' ' << *tritr1;}
            if(t==1)
            {fout1 << ' ' << *tritr2<< ' ' << *tritr3;}
            if(t==2)
            {fout1 << ' ' << *tritr<< ' ' << *tritr3;}
            fout1 << ' ' << *tritr4<<endl;
            ///Refinement of triangles
            if (t==3)
            {///center refinement of triangles
            fout1<<endl<< ' ' << tritrCentX<< ' ' << tritrCentY<<' ' <<*tritr4<<endl;
            fout1<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr4<<endl;

            fout1<<endl<< ' ' << tritrCentX<< ' ' << tritrCentY<<' ' <<*tritr4<<endl;
            fout1<< ' ' << *tritr2<< ' ' << *tritr3<<' ' <<*tritr4<<endl;

            fout1<<endl<< ' ' << tritrCentX<< ' ' << tritrCentY<<' ' <<*tritr4<<endl;
            fout1<< ' ' << *tritr<< ' ' << *tritr3<<' ' <<*tritr4<<endl;
            ///edge refinement of triangles
            fout1<<endl<< ' ' << *tritr-15<< ' ' << *tritr1<<' ' <<*tritr4<<endl;
            fout1<< ' ' << tritrCentX<<' ' <<tritrCentY<<' ' <<*tritr4<<endl;
            fout1 << ' ' << *tritr2<< ' ' << *tritr3<<' ' <<*tritr4<<endl;
            fout1 << ' ' << *tritr-15<< ' ' << *tritr1<<' ' <<*tritr4<<endl;}
        }
    }
    if (m>4)
    {   tritr5=The_Triangle.begin();
        advance (tritr5,5);
        fout1 << ' ' << *tritr<< ' ' << *tritr6<< ' ' << *tritr6<<endl;
        fout1 << ' ' << *tritr6<< ' ' << *tritr6<< ' ' << *tritr6<<endl<<endl;
        fout1 << ' ' << *tritr<< ' ' <<  *tritr5<< ' ' << *tritr6<<endl;
        fout1 << ' ' << *tritr6<< ' ' << *tritr5<< ' ' << *tritr6<<endl;
        }
        fout1<<endl;
        The_Triangle.clear();
        z++;
    }
    fout1.close();

    z=1;
    for (int m=0;m<5;m++)
    {///start for loop for loading lists for right lower tier
        The_Triangle.push_back(T.XR2());
        The_Triangle.push_back(T.YR2()+15.00*m);
        The_Triangle.push_back(xxx=38+(y/2));
        The_Triangle.push_back(T.YRR2()*z);
        The_Triangle.push_back(T.RZ2());
        The_Triangle.push_back(x=78-(4*y));

        for(int t=0;t<4;t++)
        {   tritr=The_Triangle.begin();
            tritr1=The_Triangle.begin();
            advance (tritr1,1);
            tritr2=The_Triangle.begin();
            advance (tritr2,2);
            tritr3=The_Triangle.begin();
            advance (tritr3,3);
            tritr4=The_Triangle.begin();
            advance (tritr4,4);
            tritr5=The_Triangle.begin();
            advance (tritr5,5);

            if(t==1)
            {fout4 << ' ' << *tritr2<< ' ' << *tritr3<< ' ' << *tritr5;}
            else{
            if(t==0||t==3)
            {fout4 << ' ' << *tritr<< ' ' << *tritr1;}
            if(t==2)
            {fout4 << ' ' << *tritr<< ' ' << *tritr3;}
            fout4 << ' ' << *tritr4;}
            fout4<<endl;
           ///Refinement of triangles for lower tier banks
            if (t==3)
            {tritrCentX=(*tritr+*tritr2)/2;
            tritrCentY=(*tritr1+*tritr3)/2;
            fout4<<endl<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr4<<endl;
            fout4<< ' ' << tritrCentX<<' ' <<tritrCentY<<' ' <<*tritr5<<endl;
            fout4<< ' ' << *tritr2<< ' ' << *tritr3<<' ' <<*tritr5<<endl;
            fout4<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr4<<endl;
            if (t==3&&m==0)
            {The_Triangle_Bank.push_back(tritrCentX);
            The_Triangle_Bank.push_back(tritrCentY);
            The_Triangle_Bank.push_back(*tritr5);
            The_Triangle_RiverX.push_back(tritrCentX);
            The_Triangle_RiverY.push_back(tritrCentY);
            The_Triangle_RiverZ.push_back(*tritr5);}}
        }
        The_Triangle_Bank.push_back(*tritr2);
        The_Triangle_Bank.push_back(*tritr3);
        The_Triangle_Bank.push_back(*tritr5);
        The_Triangle_RiverX.push_back(*tritr2);
        The_Triangle_RiverZ.push_back(*tritr5);
        The_Triangle_RiverY.push_back(*tritr3);
        fout4<<endl;
        The_Triangle.clear();
        z++;
    }
    ///loop to fill in the gaps for the river
    for(int w=0; w<2; w++)
        {tritr=The_Triangle_Bank.begin();
        tritr1=The_Triangle_Bank.begin();
        tritr2=The_Triangle_Bank.begin();
        advance (tritr1,1); advance (tritr2,2);
        fout4<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl;
        advance (tritr,3); advance (tritr1,3);  advance (tritr2,3);
        fout4<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl;
        advance (tritr,3); advance (tritr1,3);  advance (tritr2,3);
        fout4<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl;
        tritr=The_Triangle_Bank.begin();
        tritr1=The_Triangle_Bank.begin();
        tritr2=The_Triangle_Bank.begin();
        advance (tritr1,1); advance (tritr2,2);
        fout4<< ' ' << *tritr<< ' ' << *tritr1<<' ' <<*tritr2<<endl<<endl;
        for(int w=0; w<9; w++){The_Triangle_Bank.pop_front();}}
        fout4.close();

        tritrXL=The_Triangle_RiverX.begin();
        tritrXR=The_Triangle_RiverX.begin();
        advance(tritrXR, 6);
        tritrY=The_Triangle_RiverY.begin();
        tritrZL=The_Triangle_RiverZ.begin();
        tritrZR=The_Triangle_RiverZ.begin();
        advance(tritrZR, 6);
    ///creates river and fills it in
     for (int m=0;m<6;m++)
     {  fout5 << ' ' << *tritrXL << ' ' << *tritrY<< ' ' << *tritrZL<<endl;
        tritrXL++,tritrZL++;
        if(m==0)
        {tritrY++;};
        fout5 << ' ' << *tritrXR << ' ' << *tritrY<< ' ' << *tritrZR<<endl<<endl;
        tritrXR++, tritrY++, tritrZR++;}
        fout5.close();

    ///splots lines to file in triangles and create plot
    fout2<<"splot \'"<<Triangle_file<<"\'using 1:2:3 notitle with lines lc rgb \"green\",\'"
    <<Triangle_file3<<"\'using 1:2:3 notitle with lines lc rgb \"sandybrown\",\'"
    <<Triangle_file2<<"\'using 1:2:3 notitle with lines lc rgb \"green\",\'"
    <<Triangle_file4<<"\'using 1:2:3 notitle with lines lc rgb \"sandybrown\",\'"
    <<Triangle_fileDyk<<"\'using 1:2:3 notitle with lines lc rgb \"red\",\'"
    <<Triangle_file5<<"\'using 1:2:3 notitle with lines lc rgb \"blue\""<<endl;

    }
    fout2.close();
    ///output commands to command file and create png files
    cout<<"command.txt complete"<<endl;
    system("gnuplot command.txt");
    return 0;
}

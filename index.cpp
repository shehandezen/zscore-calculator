#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class BioStudent
{
public:
    char name[30];
    double bio;
    double physics;
    double chemistry;
    double zScore;

    void getdata();
};

void BioStudent::getdata()
{
    cout << "Student's name: ";
    cin >> name;
    cout << "Enter marks of Biology: ";
    cin >> bio;
    cout << "Enter marks of Physics: ";
    cin >> physics;
    cout << "Enter marks of Chemistry: ";
    cin >> chemistry;
    cout << "" << endl;
}

class MathStudent
{

public:
    char name[30];
    double combinedMaths;
    double physics;
    double chemistry;
    double zScore;

    void getdata();
};

void MathStudent::getdata()
{
    cout << "Student's name: ";
    cin >> name;
    cout << "Enter marks of Combined Maths: ";
    cin >> combinedMaths;
    cout << "Enter marks of Physics: ";
    cin >> physics;
    cout << "Enter marks of Chemistry: ";
    cin >> chemistry;
    cout << "" << endl;
}

int main()
{

    int selection;

    char restart;
    bool isRestart = true;
    double meanOfBio, meanOfPhysics, meanOfChemistry, meanOfCombinedMaths;

    while (isRestart)
    {
 

        cout << "Z-SCORE CALCULATOR" << endl;
        cout << "Select subject stream." << endl;
        cout << " 1.Bioscience Stream" << endl;
        cout << " 2.Math Stream" << endl;
        cout << "Enter selection (1/2): ";
        cin >> selection;
        cout << "" << endl;

        if (selection == 1)
        {
            BioStudent studentBio[120];
            int nb, ib;
            double sumBio, sumPhy, sumChe;
            cout << "Enter Number of bio Students : ";
            cin >> nb;
            // get data from user
            for (ib = 0; ib < nb; ib++)
            {
                cout << ib + 1 << ". ";
                cout << "Student" << endl;
                studentBio[ib].getdata();
            }

            cout << "Calculating sum of marks ..." << endl;

            // calculate total of each subject
            for (ib = 0; ib < nb; ib++)
            {
                sumBio = (sumBio + studentBio[ib].bio);
                sumPhy = (sumPhy + studentBio[ib].physics);
                sumChe = (sumChe + studentBio[ib].chemistry);
            }

            cout << "Calculating Mean of each subject ..." << endl;
            // calculate the mean
            meanOfBio = (sumBio / nb);
            meanOfPhysics = (sumPhy / nb);
            meanOfChemistry = (sumChe / nb);

            double totalMeanBio, totalMeanPhy, totalMeanChe, varianceBio, variancePhy, varianceChe, deviationBio, deviationPhy, deviationChe, zBio, zPhy, zChe, zScore;

            // calculate total of means for each subject
            for (ib = 0; ib < nb; ib++)
            {
                totalMeanBio = totalMeanBio + ((studentBio[ib].bio - meanOfBio) * (studentBio[ib].bio - meanOfBio));
                totalMeanPhy = totalMeanPhy + ((studentBio[ib].physics - meanOfPhysics) * (studentBio[ib].physics - meanOfPhysics));
                totalMeanChe = totalMeanChe + ((studentBio[ib].chemistry - meanOfChemistry) * (studentBio[ib].chemistry - meanOfChemistry));
            }
            cout << "Calculating variance of each subject ..." << endl;
            // calculate variance of each subject
            varianceBio = (totalMeanBio / nb);
            variancePhy = (totalMeanPhy / nb);
            varianceChe = (totalMeanChe / nb);
            cout << "Calculating Standard Deviations ..." << endl;
            // calculate standard deviations
            deviationBio = sqrt(varianceBio);
            deviationPhy = sqrt(variancePhy);
            deviationChe = sqrt(varianceChe);
            cout << "Calculating z-scores of each subject ..." << endl;
            // caculate z-scores of each subject and calculate average of z-score
            for (ib = 0; ib < nb; ib++)
            {
                zBio = (studentBio[ib].bio - meanOfBio) / deviationBio;
                zPhy = (studentBio[ib].physics - meanOfPhysics) / deviationPhy;
                zChe = (studentBio[ib].chemistry - meanOfChemistry) / deviationChe;
                cout << "Calculating z-score of " << studentBio[ib].name << endl;
                // final z-score
                zScore = (zBio + zPhy + zChe) / 3;
                // put z-scores to each student's object
                studentBio[ib].zScore = zScore;
            }

            cout << "Calculations finished!.." << endl;
            cout << "Generating Csv File..." << endl;

            // create csv file
            std::ofstream bioZscorefile;
            bioZscorefile.open("bio-zcores.csv");
            bioZscorefile << "Name,Biology,Chemistry,Physics,Z-Score, \n";
            cout << "Writing data to csv file..." << endl;
            for (ib = 0; ib < nb; ib++)
            {

                bioZscorefile << studentBio[ib].name << "," << studentBio[ib].bio << "," << studentBio[ib].chemistry << "," << studentBio[ib].physics << "," << studentBio[ib].zScore << ",\n";
            }
            // close file
            bioZscorefile.close();
            cout << "Task finished !" << endl;
            cout << "Your csv generated. You can collect it. File name : bio-zcores.csv" << endl;
            cout << "Shutdown app ..." << endl;

            isRestart = false;
        }
        else if (selection == 2)
        {
            MathStudent studentMath[200];
            int nm, im;
            double sumCom, sumPhy, sumChe;
            cout << "Enter Number of Math Students : ";
            cin >> nm;
            // get data from user
            for (im = 0; im < nm; im++)
            {
                cout << im + 1 << ". ";
                cout << "Student" << endl;
                studentMath[im].getdata();
            }

            cout << "Calculating sum of marks ..." << endl;

            // calculate total of each subject
            for (im = 0; im < nm; im++)
            {
                sumCom = (sumCom + studentMath[im].combinedMaths);
                sumPhy = (sumPhy + studentMath[im].physics);
                sumChe = (sumChe + studentMath[im].chemistry);
            }

            cout << "Calculating Mean of each subject ..." << endl;
            // calculate the mean
            meanOfCombinedMaths = (sumCom / nm);
            meanOfPhysics = (sumPhy / nm);
            meanOfChemistry = (sumChe / nm);

            double totalMeanCom, totalMeanPhy, totalMeanChe, varianceCom, variancePhy, varianceChe, deviationCom, deviationPhy, deviationChe, zCom, zPhy, zChe, zScore;

            // calculate total of means for each subject
            for (im = 0; im < nm; im++)
            {
                totalMeanCom = totalMeanCom + ((studentMath[im].combinedMaths - meanOfCombinedMaths) * (studentMath[im].combinedMaths - meanOfCombinedMaths));
                totalMeanPhy = totalMeanPhy + ((studentMath[im].physics - meanOfPhysics) * (studentMath[im].physics - meanOfPhysics));
                totalMeanChe = totalMeanChe + ((studentMath[im].chemistry - meanOfChemistry) * (studentMath[im].chemistry - meanOfChemistry));
            }
            cout << "Calculating variance of each subject ..." << endl;
            // calculate variance of each subject
            varianceCom = (totalMeanCom / nm);
            variancePhy = (totalMeanPhy / nm);
            varianceChe = (totalMeanChe / nm);
            cout << "Calculating Standard Deviations ..." << endl;
            // calculate standard deviations
            deviationCom = sqrt(varianceCom);
            deviationPhy = sqrt(variancePhy);
            deviationChe = sqrt(varianceChe);
            cout << "Calculating z-scores of each subject ..." << endl;
            // caculate z-scores of each subject and calculate average of z-score
            for (im = 0; im < nm; im++)
            {
                zCom = (studentMath[im].combinedMaths - meanOfCombinedMaths) / deviationCom;
                zPhy = (studentMath[im].physics - meanOfPhysics) / deviationPhy;
                zChe = (studentMath[im].chemistry - meanOfChemistry) / deviationChe;
                cout << "Calculating z-score of " << studentMath[im].name << endl;
                // final z-score
                zScore = (zCom + zPhy + zChe) / 3;
                // put z-scores to each student's object
                studentMath[im].zScore = zScore;
            }

            cout << "Calculations finished!.." << endl;
            cout << "Generating Csv File..." << endl;

            // create csv file
            std::ofstream mathZscorefile;
            mathZscorefile.open("math-zcores.csv");
            mathZscorefile << "Name,Combined Maths,Chemistry,Physics,Z-Score, \n";
            cout << "Writing data to csv file..." << endl;
            for (im = 0; im < nm; im++)
            {

                mathZscorefile << studentMath[im].name << "," << studentMath[im].combinedMaths << "," << studentMath[im].chemistry << "," << studentMath[im].physics << "," << studentMath[im].zScore << ",\n";
            }
            // close file
            mathZscorefile.close();
            cout << "Task finished !" << endl;
            cout << "Your csv generated. You can collect it. File name : math-zcores.csv" << endl;
            cout << "Shutdown app ..." << endl;

            isRestart = false;
        }
        else
        {
            cout << "Invalid selection." << endl;
            continue;
        }
    }

    return 0;
}
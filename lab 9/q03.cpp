#include<iostream>
#include<string>
using namespace std;

class Patientrecord; 

class Receptionistinterface{
public:
    virtual void displayinfo(const Patientrecord& record) = 0;
    virtual ~Receptionistinterface() = default;
};

class Doctorinterface{
public:
    virtual void updatemedicalhistory(Patientrecord& record, const string& newentry) = 0;
    virtual void showmedicaldata(const Patientrecord& record) = 0;
    virtual ~Doctorinterface() = default;
};

class Billinginterface {
public:
    virtual void addbillingdetail(Patientrecord& record, const string& billinginfo) = 0;
    virtual void displaybillinginfo(const Patientrecord& record) = 0;
    virtual ~Billinginterface() = default;
};

class Patientrecord {
private:
    string name;
    int id;
    string dob;
    string medicalhistory[5];
    int medicalhistorycount = 0;
    string currenttreatment;
    string billingdetail[5]; 
    int billingdetailcount = 0; 
public:
    Patientrecord(string name, int id, string dob) : name(name), id(id), dob(dob) {}

    void getpublicdata() const {
        cout<< "Patient ID: " << id << "\nName: " << name << "\ndob: " << dob << "\n";
    }
private:
    void addmedicalhistory(const string& entry) {
        if (medicalhistorycount < 5) 
		{ 
            medicalhistory[medicalhistorycount++] = entry;
        } else 
		{
            cout<< "Medical history limit reached." << endl;
        }
    }

    void showmedicalhistory() const {
        cout<< "Medical History: "<< endl;
        for(int i=0; i<medicalhistorycount; ++i) 
		{
            cout<< "- " << medicalhistory[i] << endl;
        }
        cout<< "Current Treatment: " << currenttreatment << endl;
    }

    void setcurrenttreatment(const string& treatment) {
        currenttreatment = treatment;
    }

    void addbilling(const string& bill) {
        if (billingdetailcount < 5) 
		{ 
            billingdetail[billingdetailcount++] = bill;
        } else 
		{
            cout<< "Billing details limit reached.\n";
        }
    }

    void showbilling() const {
        cout<< "Billing Information:\n";
        for (int i=0; i<billingdetailcount; ++i) 
		{
            cout<< "- " << billingdetail[i] << "\n";
        }
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor : public Doctorinterface {
public:
    void updatemedicalhistory(Patientrecord& record, const string& newentry) override {
        record.addmedicalhistory(newentry);
        record.setcurrenttreatment("Follow-up in 2 weeks");
    }

    void showmedicaldata(const Patientrecord& record) override {
        record.showmedicalhistory();
    }
};

class Billing : public Billinginterface {
public:
    void addbillingdetail(Patientrecord& record, const string& billinginfo) override {
        record.addbilling(billinginfo);
    }

    void displaybillinginfo(const Patientrecord& record) override {
        record.showbilling();
    }
};

class Receptionist : public Receptionistinterface {
public:
    void displayinfo(const Patientrecord& record) override {
        record.getpublicdata();
    }
};

int main() 
{
    Patientrecord patient("Ali", 001, "12-07-2000");
    Doctor doctor;
    Billing billing;
    Receptionist receptionist;
    cout<< "\n--- Receptionist Access ---\n";
    receptionist.displayinfo(patient);
    cout<< "\n--- Doctor Access ---\n";
    doctor.updatemedicalhistory(patient, "Diagnosed with seasonal allergies.");
    doctor.showmedicaldata(patient);
    cout<< "\n--- Billing Access ---\n";
    billing.addbillingdetail(patient, "Consultation: $110");
    billing.displaybillinginfo(patient);
    cout<< "\n--- Unauthorized Access Attempt ---\n";
    return 0;
}

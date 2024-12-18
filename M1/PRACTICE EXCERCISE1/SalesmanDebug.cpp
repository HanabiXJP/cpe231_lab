#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p; // จำนวนประเทศและจำนวนเที่ยวบิน
    cin >> n >> p;
    
    string country1, country2; // ตัวแปรสำหรับเก็บชื่อประเทศ
    int cost; // ตัวแปรสำหรับเก็บค่าบิน

    // เวกเตอร์สำหรับเก็บชื่อประเทศในรูปแบบ (ชื่อประเทศ, ดัชนี)
    vector<pair<string, int>> countries;
    countries.push_back(make_pair("THA", 0)); // "THA" เป็นประเทศเริ่มต้น

    // เมทริกซ์เชื่อมต่อ (adjacency matrix) เพื่อเก็บค่าบิน
    vector<vector<int>> flightCost(n + 1, vector<int>(n + 1, 0));

    // รับข้อมูลเที่ยวบิน
    for (int i = 0; i < p; i++) {
        cin >> country1 >> country2 >> cost;
        int found1 = -1, found2 = -1;

        // ตรวจสอบว่าประเทศนี้มีอยู่แล้วในรายการหรือไม่
        for (int j = 0; j < countries.size(); j++) {
            if (country1 == countries[j].first) {
                found1 = j;
            }
            if (country2 == countries[j].first) {
                found2 = j;
            }
        }

        // ถ้าไม่เจอ ให้เพิ่มประเทศนั้นลงในรายการ
        if (found1 == -1) {
            countries.push_back(make_pair(country1, countries.size()));
            found1 = countries.size() - 1;
        }
        if (found2 == -1) {
            countries.push_back(make_pair(country2, countries.size()));
            found2 = countries.size() - 1;
        }

        // กำหนดค่าเที่ยวบินลงในเมทริกซ์เชื่อมต่อ
        flightCost[found1][found2] = flightCost[found2][found1] = cost;
        
        // Debug: แสดงผลข้อมูลที่อ่านเข้ามา
        cout << "Read flight: " << country1 << " to " << country2 << " with cost " << cost << endl;
        cout << "Matrix Index: " << found1 << " to " << found2 << " with cost " << flightCost[found1][found2] << endl;
    }

    int maxCost = 0; // ตัวแปรสำหรับเก็บค่าบินสูงสุด
    vector<pair<string, int>> optimalPath; // เวกเตอร์สำหรับเก็บเส้นทางที่แพงที่สุด

    // การค้นหาทั้งหมดด้วยวิธี brute-force เพื่อหาเส้นทางที่มีค่าใช้จ่ายสูงสุด
    do {
        int currentCost = 0;

        // Debug: แสดงเส้นทางที่กำลังตรวจสอบ
        cout << "Checking path: ";
        for (int i = 0; i < n + 1; i++) {
            cout << countries[i].first << " ";
        }
        cout << endl;

        // คำนวณค่าบินทั้งหมดของเส้นทางที่ทดสอบอยู่
        for (int i = 0; i < n; i++) {
            currentCost += flightCost[countries[i].second][countries[i + 1].second];
        }
        currentCost += flightCost[countries[n].second][countries[0].second]; // กลับไปยังจุดเริ่มต้น

        // Debug: แสดงค่าบินรวมของเส้นทาง
        cout << "Current cost: " << currentCost << endl;

        // อัปเดตค่าใช้จ่ายสูงสุดและเส้นทางที่ดีที่สุดหากพบค่าใช้จ่ายที่สูงกว่า
        if (currentCost > maxCost) {
            maxCost = currentCost;
            optimalPath = countries;
        }
    } while (next_permutation(countries.begin() + 1, countries.end())); // ลองทุกเส้นทางที่เป็นไปได้โดยเริ่มจากประเทศที่สอง

    // แสดงผลลัพธ์ของเส้นทางที่แพงที่สุด
    cout << "Most expensive path: ";
    for (int i = 0; i < n + 1; i++) {
        cout << optimalPath[i].first << " ";
    }
    cout << "THA" << endl;
    cout << "Maximum cost: " << maxCost << endl;

    return 0;
}

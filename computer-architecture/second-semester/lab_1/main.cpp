#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sFileName;
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    int Width, Height;
    RGBTRIPLE* inBuf;
    WORD* outBuf;
    HANDLE hInputFile, hOutFile;
    DWORD RW;

    cout << "Enter the full name, please: ";
    cin >> sFileName;
    hInputFile = CreateFile(sFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hInputFile == INVALID_HANDLE_VALUE) {
        cout << "Error: Cannot open input file!" << endl;
        return -1;
    }

    hOutFile = CreateFile("Result_16bit.bmp", GENERIC_WRITE, 0, NULL, CREATE_NEW, 0, NULL);
    if (hOutFile == INVALID_HANDLE_VALUE) {
        CloseHandle(hInputFile);
        cout << "Error: Cannot create output file!" << endl;
        return -1;
    }

    ReadFile(hInputFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    ReadFile(hInputFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);

    bmpFileHeader.bfOffBits = sizeof(bmpFileHeader) + sizeof(bmpInfoHeader);
    bmpInfoHeader.biBitCount = 16;
    bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 2;

    WriteFile(hOutFile, &bmpFileHeader, sizeof(bmpFileHeader), &RW, NULL);
    WriteFile(hOutFile, &bmpInfoHeader, sizeof(bmpInfoHeader), &RW, NULL);

    Width = bmpInfoHeader.biWidth;
    Height = bmpInfoHeader.biHeight;

    inBuf = new RGBTRIPLE[Width];
    outBuf = new WORD[Width];

    for (int i = 0; i < Height; i++) {
        ReadFile(hInputFile, inBuf, sizeof(RGBTRIPLE) * Width, &RW, NULL);
        for (int j = 0; j < Width; j++) {
            WORD pixel16 = ((inBuf[j].rgbtRed >> 3) << 11) |
                           ((inBuf[j].rgbtGreen >> 2) << 5) |
                           (inBuf[j].rgbtBlue >> 3);
            outBuf[j] = pixel16;
        }
        WriteFile(hOutFile, outBuf, sizeof(WORD) * Width, &RW, NULL);
    }

    delete[] inBuf;
    delete[] outBuf;
    CloseHandle(hInputFile);
    CloseHandle(hOutFile);

    cout << "Conversion to 16-bit BMP completed successfully!" << endl;
    system("pause");
    return 0;
}

//creating camera filters using c++ opencv library


#include <opencv2/opencv.hpp>

using namespace cv;
//using namespace std;

int main() {
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the webcam." << std::endl;
        return -1;
    }

    while (true) {
        Mat img;

        // Read a frame from the webcam
        cap >> img;

        // Display options to the user
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Grayscale" << std::endl;
        std::cout << "2. Hue" << std::endl;
        std::cout << "3. RGB" << std::endl;
        std::cout << "4. Gaussian Blur" << std::endl;
        std::cout << "5. Exit" << std::endl;

        // Prompt user for choice
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Apply the selected filter
        switch (choice) {
            case 1:
                cvtColor(img, img, COLOR_BGR2GRAY);
                break;
            case 2:
                cvtColor(img, img, COLOR_BGR2HSV);
                break;
            case 3:
                // Keep the RGB color space
                break;
            case 4:
                GaussianBlur(img, img, Size(5, 5), 0);
                break;
            case 5:
                // Exit the program
                cap.release();
                destroyAllWindows();
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                continue;
        }

        // Display the frame
        imshow("Webcam Feed", img);

        // Break the loop if the user presses the 'ESC' key (ASCII code 27)
        if (waitKey(1) == 27) {
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}

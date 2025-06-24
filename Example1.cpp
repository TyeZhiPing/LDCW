#include <iostream>
#include <cstdlib> // For system()
#include <iomanip> // For setprecision
using namespace std;

// Cross-platform clear screen
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Ask one question with input validation and scoring
bool askQuestion(int qNum, int total, string question, string A, string B, string C, string D, char correctAnswer)
{
    string input;
    char answer;

    while (true)
    {
        clearScreen();
        cout << "=== Cybersecurity Quiz ===" << endl;
        cout << "Question " << qNum << " of " << total << "\n\n";
        cout << question << "\n"
             << endl;
        cout << "A) " << A << endl;
        cout << "B) " << B << endl;
        cout << "C) " << C << endl;
        cout << "D) " << D << endl;
        cout << "\nEnter your answer (A, B, C, or D): ";
        cin >> input;

        if (input.length() == 1)
        {
            answer = toupper(input[0]);
            if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D')
            {
                clearScreen();
                cout << "Question " << qNum << " Answered\n\n";
                if (answer == correctAnswer)
                {
                    cout << "[Correct] Well done!" << endl;
                    return true;
                }
                else
                {
                    cout << "[Incorrect] The correct answer was " << correctAnswer << "." << endl;
                    return false;
                }
            }
        }

        cout << "\n[Invalid Input] Please enter a single letter: A, B, C, or D." << endl;
        cout << "Press Enter to try again...";
        cin.ignore();
        cin.get();
    }
}

int main()
{
    int score = 0;
    const int totalQuestions = 10;

    clearScreen();
    cout << "=== Welcome to the Cybersecurity Awareness Quiz ===\n"
         << endl;
    cout << "Test your knowledge and learn how to stay safe online." << endl;
    cout << "Press Enter to begin...";
    cin.ignore();
    cin.get();

    // Questions
    score += askQuestion(1, totalQuestions, "What is the most secure way to protect your online accounts?",
                         "Use a short password you can remember easily",
                         "Use the same password for all accounts",
                         "Use two-factor authentication (2FA)",
                         "Share your password with someone you trust", 'C');

    cin.ignore();
    cin.get();

    score += askQuestion(2, totalQuestions, "Which of the following is a sign of a phishing email?",
                         "Email from a known contact with personal info",
                         "Poor grammar and a request to click an urgent link",
                         "Personalized email with no attachments",
                         "A newsletter you subscribed to", 'B');

    cin.ignore();
    cin.get();

    score += askQuestion(3, totalQuestions, "What should you do if you receive an unexpected file from a stranger?",
                         "Open it to see what's inside",
                         "Forward it to friends",
                         "Delete it without opening and report it",
                         "Upload it to social media", 'C');

    cin.ignore();
    cin.get();

    score += askQuestion(4, totalQuestions, "What is a strong password?",
                         "123456",
                         "Your name and birthdate",
                         "A mix of letters, numbers, and symbols",
                         "Password123", 'C');

    cin.ignore();
    cin.get();

    score += askQuestion(5, totalQuestions, "What does 2FA (Two-Factor Authentication) require?",
                         "Only a password",
                         "A password and username",
                         "Two different devices",
                         "Password plus an extra verification step like SMS code", 'D');

    cin.ignore();
    cin.get();

    score += askQuestion(6, totalQuestions, "Which is the safest network for online banking?",
                         "Public Wi-Fi at a cafe",
                         "Your friend's Wi-Fi",
                         "Your mobile hotspot with encryption",
                         "Any Wi-Fi as long as you use a browser", 'C');

    cin.ignore();
    cin.get();

    score += askQuestion(7, totalQuestions, "Which action best protects your device from malware?",
                         "Clicking on free software ads",
                         "Installing antivirus software and updating it regularly",
                         "Opening email attachments from unknown senders",
                         "Ignoring software updates", 'B');

    cin.ignore();
    cin.get();

    score += askQuestion(8, totalQuestions, "What is the main purpose of a firewall?",
                         "Speed up your internet",
                         "Block pop-up ads",
                         "Prevent unauthorized access to or from a network",
                         "Fix bugs in your system", 'C');

    cin.ignore();
    cin.get();

    score += askQuestion(9, totalQuestions, "What should you do before clicking a suspicious link?",
                         "Click to see where it goes",
                         "Ignore the message and report it",
                         "Forward it to friends",
                         "Copy and paste the link into your browser", 'B');

    cin.ignore();
    cin.get();

    score += askQuestion(10, totalQuestions, "What is social engineering in cybersecurity?",
                         "Using software to manage accounts",
                         "Building social media apps",
                         "Manipulating people into revealing confidential information",
                         "Sending encrypted messages", 'C');

    cin.ignore();
    cin.get();
    clearScreen();

    // Final Result
    double percent = (score / (double)totalQuestions) * 100.0;
    cout << "=== Quiz Completed ===\n"
         << endl;
    cout << "You scored: " << score << " out of " << totalQuestions << " (" << fixed << setprecision(1) << percent << "%)\n"
         << endl;

    if (score == 10)
    {
        cout << "Perfect Score! You're a cybersecurity expert!" << endl;
    }
    else if (score >= 8)
    {
        cout << "Great job! You have strong cybersecurity awareness." << endl;
    }
    else if (score >= 5)
    {
        cout << "Good effort! Keep learning to improve your knowledge." << endl;
    }
    else
    {
        cout << "You should review cybersecurity basics. Stay safe online!" << endl;
    }

    cout << "\nThank you for taking the quiz. Practice smart digital habits!" << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Convert string to lowercase
string toLower(string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

// Check if keyword exists in user input
bool containsKeyword(string input, string keyword)
{
    return toLower(input).find(toLower(keyword)) != string::npos;
}

int main()
{
    string userInput;

    cout << "Welcome to ShopBot! How can I assist you today?\n";
    cout << "Type 'exit' to end the chat.\n\n";

    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        if (toLower(userInput) == "exit")
        {
            cout << "ShopBot: Thank you for visiting. Have a great day!\n";
            break;
        }

        if (containsKeyword(userInput, "price") || containsKeyword(userInput, "cost"))
        {
            cout << "ShopBot: Our prices vary by product. Could you tell me which item you're interested in?\n";
        }
        else if (containsKeyword(userInput, "refund") || containsKeyword(userInput, "return"))
        {
            cout << "ShopBot: You can return any item within 30 days for a full refund.\n";
        }
        else if (containsKeyword(userInput, "order") || containsKeyword(userInput, "track"))
        {
            cout << "ShopBot: You can track your order using the tracking ID sent to your email.\n";
        }
        else if (containsKeyword(userInput, "hello") || containsKeyword(userInput, "hi"))
        {
            cout << "ShopBot: Hello! How can I help you today?\n";
        }
        else if (containsKeyword(userInput, "availability") || containsKeyword(userInput, "stock"))
        {
            cout << "ShopBot: Please provide the product name so I can check its availability.\n";
        }
        else if (containsKeyword(userInput, "hours") || containsKeyword(userInput, "timing"))
        {
            cout << "ShopBot: Our store is open from 9 AM to 9 PM, Monday to Saturday.\n";
        }
        else if (containsKeyword(userInput, "contact") || containsKeyword(userInput, "support"))
        {
            cout << "ShopBot: You can contact our support team at support@shopbot.com or call 1800-123-456.\n";
        }
        else if (containsKeyword(userInput, "delivery") || containsKeyword(userInput, "shipping"))
        {
            cout << "ShopBot: Standard delivery takes 3-5 business days.\n";
        }
        else if (containsKeyword(userInput, "discount") || containsKeyword(userInput, "offer"))
        {
            cout << "ShopBot: We have up to 30% off on electronics this week!\n";
        }
        else
        {
            cout << "ShopBot: I'm sorry, I didn't understand that. Could you please rephrase?\n";
        }
    }

    return 0;
}
// This code implements a simple chatbot that can respond to various user queries related to shopping.
// It uses string manipulation to check for keywords in the user's input and provides appropriate responses.
// The chatbot can handle inquiries about prices, refunds, order tracking, store hours, and more.
// The program runs in a loop until the user types 'exit', at which point it thanks the user and ends the chat.
// The chatbot is designed to be user-friendly and provide quick responses to common shopping-related questions.
// The code is written in C++ and utilizes standard libraries for string handling and input/output operations.
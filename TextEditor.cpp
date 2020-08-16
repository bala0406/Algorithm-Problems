#include<iostream>
#include<stack>


class TextEditor
{
private:
    std::stack<std::string> currentTextState;

public:
    std::string appendCharacter(std::string &w, std::string &character)
    {
        currentTextState.push(w);
        w.append(character);
        return w;
    }

    std::string deleteCharacter(std::string &w, int &characterCount)
    {
        currentTextState.push(w);
        for (int i = 0; i < characterCount; i++)
        {
            w.pop_back();
        }
        return w;
    }

    void print(std::string &w, int &index)
    {
        std::cout << w[index - 1] << "\n";
    }

    std::string undo()
    {
        std::string w;
        if (!currentTextState.empty())
        {
            w = currentTextState.top();
            currentTextState.pop();
        }
        return w;
    }
};

int main()
{
    int count;
    std::cin >> count;
    std::string text = "";
    TextEditor *textEditor = new TextEditor;

    for (int i = 0; i < count; i++)
    {
        int operation;
        std::cin >> operation;
        if (operation == 1)
        {
            std::string argument;
            std::cin >> argument;
            text = textEditor->appendCharacter(text, argument);
        }
        else if (operation == 2)
        {
            int argument;
            std::cin >> argument;
            text = textEditor->deleteCharacter(text, argument);
        }
        else if (operation == 3)
        {
            int argument;
            std::cin >> argument;
            textEditor->print(text, argument);
        }
        else if (operation == 4)
        {
            text = textEditor->undo();
        }
        // std::cout << text;
    }
    return 0;
}

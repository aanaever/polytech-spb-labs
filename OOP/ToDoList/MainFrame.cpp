#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"
#include <fstream>
#include <iomanip>
#include <ctime>
#include <mutex>
#include <wx/renderer.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls(); 
	BindEventHandlers(); 
	AddSavedTasks(); 

}

void MainFrame::CreateControls()
{
	//wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont headlineFont(28, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Consolas");
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	wxFont customFont(17, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Consolas");
	wxFont customFont2(17, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Consolas");
	wxColour textColor(wxColour(95, 59, 60));

	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	panel->SetBackgroundColour(wxColour(249, 244, 248));

	headlineText = new wxStaticText(panel, wxID_ANY, "Ñïèñîê äåë",
		wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
	headlineText->SetFont(headlineFont);
	headlineText->SetForegroundColour(textColor);
	headlineText->SetBackgroundColour(wxColour(239, 208, 208));


	inputField = new wxTextCtrl(panel, wxID_ANY, "",
		wxPoint(100, 80), wxSize(600, 35), wxTE_PROCESS_ENTER);


	addButton = new wxButton(inputField, wxID_ANY, "+", wxPoint(565, 1), wxSize(28, 28));
	addButton->SetBackgroundColour(wxColour(255, 245, 238)); 
	addButton->SetForegroundColour(wxColour(95, 59, 60));


	checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 350));
	checkListBox->SetFont(customFont);
	checkListBox->SetForegroundColour(wxColour(95, 59, 60));

	
	progressText = new wxStaticText(panel, wxID_ANY, "0%", wxPoint(645, 490), wxDefaultSize);
	progressText->SetFont(customFont2);
	progressText->SetForegroundColour(wxColour(95, 59, 60));


	
	progressGauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(100, 490), wxSize(520, 25), wxGA_HORIZONTAL);
	progressGauge->SetValue(0);


	clearButton = new wxButton(panel, wxID_ANY, "Î÷èñòèòü", wxPoint(550, 525), wxSize(150, 35));
	clearButton->SetFont(customFont2);
	clearButton->SetBackgroundColour(wxColour(239, 208, 208));
	clearButton->SetForegroundColour(wxColour(95, 59, 60));

	currentDateText = new wxStaticText(panel, wxID_ANY, GetCurrentDate(),
		wxPoint(50, 33), wxDefaultSize, wxALIGN_RIGHT);
	currentDateText->SetFont(customFont);
	currentDateText->SetForegroundColour(textColor);
	headlineText->SetBackgroundColour(wxColour(239, 208, 208));


	editButton = new wxButton(panel, wxID_ANY, "Ðåäàêòèðîâàòü", wxPoint(100, 525), wxSize(200, 35));
	editButton->SetFont(customFont2);
	editButton->SetBackgroundColour(wxColour(239, 208, 208));
	editButton->SetForegroundColour(wxColour(95, 59, 60));
}

void MainFrame::BindEventHandlers()
{
	addButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddButtonClicked, this);
	inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnInputEnter, this);
	checkListBox->Bind(wxEVT_KEY_DOWN, &MainFrame::OnListKeyDown, this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::OnClearButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWindowClosed, this);

	checkListBox->Bind(wxEVT_CHECKLISTBOX, &MainFrame::OnCheckListBoxToggle, this);
	//editButton->Bind(wxEVT_BUTTON, &MainFrame::OnEditItem, this);
	//inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::OnEditItem, this);
	editButton->Bind(wxEVT_BUTTON, &MainFrame::OnEditItem, this);
}




void MainFrame::AddSavedTasks()
{
	std::vector<Task> tasks = LoadTasksFromFile("tasks.txt");

	for (const Task& task : tasks) {
		int index = checkListBox->GetCount();
		checkListBox->Insert(task.description, index);
		checkListBox->Check(index, task.done);
	}

	UpdateProgressGauge();

	std::time_t currentTime = std::time(nullptr);
	std::tm* timeinfo = std::localtime(&currentTime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", timeinfo);

	std::ofstream dateFile("date.txt");
	dateFile << buffer;
	dateFile.close();

	currentDateText->SetLabel(wxString(buffer));
}


void MainFrame::OnAddButtonClicked(wxCommandEvent& evt)
{
	AddTaskFromInput();

	UpdateProgressGauge();

}

void MainFrame::OnInputEnter(wxCommandEvent& evt)
{
	AddTaskFromInput();
}

void MainFrame::OnListKeyDown(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_DELETE:
		DeleteSelectedTask();
		break;
	case WXK_UP:
		MoveSelectedTask(-1);
		break;
	case WXK_DOWN:
		MoveSelectedTask(1);
		break;
	}

	UpdateProgressGauge();
}

void MainFrame::OnClearButtonClicked(wxCommandEvent& evt)
{
	if (checkListBox->IsEmpty()) {
		return;
	}

	wxMessageDialog dialog(this, "Âû òî÷íî õîòèòå î÷èñòèòü âñå çàäà÷è?",
		"Î÷èñòèòü", wxYES_NO | wxCANCEL);
	int result = dialog.ShowModal();

	if (result == wxID_YES) {
		checkListBox->Clear();
	}

	UpdateProgressGauge();

}

void MainFrame::OnWindowClosed(wxCloseEvent& evt)
{
	std::vector<Task> tasks;
	for (int i = 0; i < checkListBox->GetCount(); i++) {
		Task task;
		task.description = checkListBox->GetString(i);
		task.done = checkListBox->IsChecked(i);
		tasks.push_back(task);
	}

	SaveTasksToFile(tasks, "tasks.txt");
	evt.Skip();

	std::ofstream dateFile("date.txt");
	dateFile << GetCurrentDate();
}

void MainFrame::OnCheckListBoxToggle(wxCommandEvent& evt)
{
	UpdateProgressGauge();
}


void MainFrame::AddTaskFromInput()
{
	wxString description = inputField->GetValue();

	if (!description.IsEmpty()) {
		checkListBox->Insert(description, checkListBox->GetCount());
		inputField->Clear();
	}

	inputField->SetFocus();

	UpdateProgressGauge();
}

void MainFrame::DeleteSelectedTask()
{

	int selectedIndex = checkListBox->GetSelection();
	 
	if (selectedIndex == wxNOT_FOUND) {
		return;
	}

	checkListBox->Delete(selectedIndex);

	UpdateProgressGauge();
}

void MainFrame::MoveSelectedTask(int offset)
{
	
	int selectedIndex = checkListBox->GetSelection();
	if (selectedIndex == wxNOT_FOUND) {
		return;
	}
	int newIndex = selectedIndex + offset;
	if (newIndex >= 0 && newIndex < checkListBox->GetCount()) {
		SwapTasks(selectedIndex, newIndex);
		checkListBox->SetSelection(newIndex, true);
	}
}
void MainFrame::SwapTasks(int i, int j)
{
	
	Task taskI{ checkListBox->GetString(i).ToStdString(), checkListBox->IsChecked(i) };
	Task taskJ{ checkListBox->GetString(j).ToStdString(), checkListBox->IsChecked(j) };

	checkListBox->SetString(i, taskJ.description);
	checkListBox->Check(i, taskJ.done);

	checkListBox->SetString(j, taskI.description);
	checkListBox->Check(j, taskI.done);
}
void MainFrame::UpdateProgressGauge()
{
	int totalTasks = checkListBox->GetCount();
	int doneTasks = 0;

	for (int i = 0; i < totalTasks; i++)
	{
		if (checkListBox->IsChecked(i))
		{
			doneTasks++;
		}
	}
	int progress = totalTasks > 0 ? (doneTasks * 100 / totalTasks) : 0;
	progressGauge->SetValue(progress);
	progressGauge->SetValue(progress);
	progressText->SetLabel(wxString::Format("%d%%", progress));
}

std::string MainFrame::GetCurrentDate() const
{
	std::ifstream dateFile("date.txt");
	std::string currentDate;
	if (dateFile >> currentDate) {
		dateFile.close();
	}
	else {
		std::time_t currentTime = std::time(nullptr);
		std::tm* timeinfo = std::localtime(&currentTime);
		char buffer[80];
		std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", timeinfo);
		currentDate = buffer;
	}
	return currentDate;
}

void MainFrame::OnEditItem(wxCommandEvent& evt)
{
	int selectedIndex = checkListBox->GetSelection();
	if (selectedIndex != wxNOT_FOUND)
	{
		wxString currentItemText = checkListBox->GetString(selectedIndex);
		wxString editedItemText = wxGetTextFromUser("Ðåäàêòèðîâàòü çàäà÷ó", "Ðåäàêòèðîâàíèå", currentItemText, this);
		if (!editedItemText.IsEmpty())
		{
			checkListBox->SetString(selectedIndex, editedItemText);
		}
	}
}

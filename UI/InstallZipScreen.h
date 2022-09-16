// Copyright (c) 2013- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include <functional>

#include "Common/UI/View.h"
#include "Common/UI/UIScreen.h"

#include "UI/MiscScreens.h"

class InstallZipScreen : public UIDialogScreenWithBackground {
public:
	InstallZipScreen(const Path &zipPath);
	virtual void update() override;
	virtual bool key(const KeyInput &key) override;

	const char *tag() const override { return "install_zip"; }

protected:
	virtual void CreateViews() override;

private:
	UI::EventReturn OnInstall(UI::EventParams &params);

	UI::Choice *installChoice_ = nullptr;
	UI::Choice *backChoice_ = nullptr;
	UI::ProgressBar *progressBar_ = nullptr;
	UI::TextView *doneView_ = nullptr;
	Path zipPath_;
	bool returnToHomebrew_ = true;
	bool installStarted_ = false;
	bool deleteZipFile_ = false;
};


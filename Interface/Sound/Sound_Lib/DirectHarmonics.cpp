# include "stdafx.h"
# include "DirectHarmonics.h"
# include "DirectSound_buffer.h"

using std::make_unique;
using namespace Interface::Sound;

DirectHarmonics::DirectHarmonics(HWND hWnd, const unsigned totalMilliSeconds) :
	buffer_(make_unique<DirectSound_buffer>())
{
	buffer_->Init(hWnd, totalMilliSeconds);
}

DirectHarmonics::~DirectHarmonics() {}

void DirectHarmonics::AddNote(const int note, const unsigned start, const unsigned duration) const
{
	const auto delta(note > noteMin_ ? note < noteMax_ ? note - noteMin_ : noteMax_ - noteMin_ : NULL);
	buffer_->AddNote(delta, start, duration);
}

void DirectHarmonics::Play() const
{
	buffer_->NormalizeAndPlay();
}

void DirectHarmonics::Stop() const
{
	buffer_->Stop();
}

void DirectHarmonics::Clear() const
{
	Stop();
	buffer_->Clear();
}
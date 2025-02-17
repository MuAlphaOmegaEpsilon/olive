/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2022 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef FOOTAGEJOB_H
#define FOOTAGEJOB_H

#include "node/project/footage/footage.h"

namespace olive {

class FootageJob : public AcceleratedJob
{
public:
  FootageJob() :
    type_(Track::kNone)
  {
  }

  FootageJob(const TimeRange &time, const QString& decoder, const QString& filename, Track::Type type, const rational& length) :
    time_(time),
    decoder_(decoder),
    filename_(filename),
    type_(type),
    length_(length)
  {
  }

  const QString& decoder() const
  {
    return decoder_;
  }

  const QString& filename() const
  {
    return filename_;
  }

  Track::Type type() const
  {
    return type_;
  }

  const VideoParams& video_params() const
  {
    return video_params_;
  }

  void set_video_params(const VideoParams& p)
  {
    video_params_ = p;
  }

  const AudioParams& audio_params() const
  {
    return audio_params_;
  }

  void set_audio_params(const AudioParams& p)
  {
    audio_params_ = p;
  }

  const QString& cache_path() const
  {
    return cache_path_;
  }

  void set_cache_path(const QString& p)
  {
    cache_path_ = p;
  }

  const rational& length() const
  {
    return length_;
  }

  void set_length(const rational& length)
  {
    length_ = length;
  }

  const TimeRange &time() const { return time_; }

private:
  TimeRange time_;

  QString decoder_;

  QString filename_;

  Track::Type type_;

  VideoParams video_params_;

  AudioParams audio_params_;

  QString cache_path_;

  rational length_;

};

}

Q_DECLARE_METATYPE(olive::FootageJob)

#endif // FOOTAGEJOB_H

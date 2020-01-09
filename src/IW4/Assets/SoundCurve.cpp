// ======================= ZoneTool =======================
// zonetool, a fastfile linker for various
// Call of Duty titles. 
//
// Project: https://github.com/ZoneTool/zonetool
// Author: RektInator (https://github.com/RektInator)
// License: GNU GPL v3.0
// ========================================================
#include "stdafx.hpp"

namespace ZoneTool
{
	namespace IW4
	{
		ISoundCurve::ISoundCurve()
		{
		}

		ISoundCurve::~ISoundCurve()
		{
		}

		void ISoundCurve::init(const std::string& name, ZoneMemory* mem)
		{
			this->name_ = name;
			this->asset_ = DB_FindXAssetHeader(this->type(), this->name().data()).soundcurve;
		}

		void ISoundCurve::prepare(ZoneBuffer* buf, ZoneMemory* mem)
		{
		}

		void ISoundCurve::load_depending(IZone* zone)
		{
		}

		std::string ISoundCurve::name()
		{
			return this->name_;
		}

		std::int32_t ISoundCurve::type()
		{
			return sndcurve;
		}

		void ISoundCurve::write(IZone* zone, ZoneBuffer* buf)
		{
			auto data = this->asset_;
			auto dest = buf->write(data);
			
			buf->push_stream(3);
			START_LOG_STREAM;

			dest->filename = buf->write_str(this->name());

			END_LOG_STREAM;
			buf->pop_stream();
			
			if (zone->get_target() != zone_target::pc)
			{
				endian_convert(&dest->filename);
				endian_convert(&dest->knotCount);

				for (auto i = 0u; i < 16; i++)
				{
					endian_convert(&dest->knots[i][0]);
					endian_convert(&dest->knots[i][1]);
				}
			}
		}

		void ISoundCurve::dump(SndCurve* asset)
		{
		}
	}
}

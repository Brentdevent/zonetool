// ======================= ZoneTool =======================
// zonetool, a fastfile linker for various
// Call of Duty titles. 
//
// Project: https://github.com/ZoneTool/zonetool
// Author: RektInator (https://github.com/RektInator)
// License: GNU GPL v3.0
// ========================================================
#pragma once

#include "../IW5/Structs.hpp"

namespace ZoneTool
{
	namespace IW4
	{
		class ISound : public IAsset
		{
		private:
			std::string name_;
			snd_alias_list_t* asset_ = nullptr;

			static void write_soundfile(IZone* zone, ZoneBuffer* buf, SoundFile* dest);
			static void write_head(IZone* zone, ZoneBuffer* buf, snd_alias_t* dest);

		public:
			static IW5::SoundChannel channel_to_iw5(IW4::SoundChannel snd_channel);
			static IW4::SoundChannel channel_to_iw4(IW5::SoundChannel snd_channel);

			static snd_alias_list_t* parse(const std::string& name, ZoneMemory* mem);

			void init(const std::string& name, ZoneMemory* mem) override;
			void prepare(ZoneBuffer* buf, ZoneMemory* mem) override;
			void load_depending(IZone* zone) override;

			std::string name() override;
			std::int32_t type() override;
			void write(IZone* zone, ZoneBuffer* buffer) override;

			static void dump(snd_alias_list_t* asset);
		};
	}
}

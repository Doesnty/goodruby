const u8 gMoveNames[][13] = {
    [MOVE_NONE] = _("-$$$$$$"),
    [MOVE_POUND] = _("Pound"),
    [MOVE_KARATE_CHOP] = _("Karate Chop"),
    [MOVE_DOUBLE_SLAP] = _("Double Slap"),
    [MOVE_COMET_PUNCH] = _("Comet Punch"),
    [MOVE_MEGA_PUNCH] = _("Mega Punch"),
    [MOVE_PAY_DAY] = _("Pay Day"),
    [MOVE_FIRE_PUNCH] = _("Fire Punch"),
    [MOVE_ICE_PUNCH] = _("Ice Punch"),
    [MOVE_THUNDER_PUNCH] = _("ThunderPunch"),
    [MOVE_SCRATCH] = _("Scratch"),
    [MOVE_VICE_GRIP] = _("Vicegrip"),
    [MOVE_GUILLOTINE] = _("Guillotine"),
    [MOVE_RAZOR_WIND] = _("Razor Wind"),
    [MOVE_SWORDS_DANCE] = _("Swords Dance"),
    [MOVE_CUT] = _("Cut"),
    [MOVE_GUST] = _("Gust"),
    [MOVE_WING_ATTACK] = _("Wing Attack"),
    [MOVE_WHIRLWIND] = _("Whirlwind"),
    [MOVE_FLY] = _("Fly"),
    [MOVE_BIND] = _("Bind"),
    [MOVE_SLAM] = _("Slam"),
    [MOVE_VINE_WHIP] = _("Vine Whip"),
    [MOVE_STOMP] = _("Stomp"),
    [MOVE_DOUBLE_KICK] = _("Double Kick"),
    [MOVE_MEGA_KICK] = _("Mega Kick"),
    [MOVE_JUMP_KICK] = _("Jump Kick"),
    [MOVE_ROLLING_KICK] = _("Rolling Kick"),
    [MOVE_SAND_ATTACK] = _("Sand-Attack"),
    [MOVE_HEADBUTT] = _("Headbutt"),
    [MOVE_HORN_ATTACK] = _("Horn Attack"),
    [MOVE_FURY_ATTACK] = _("Fury Attack"),
    [MOVE_HORN_DRILL] = _("Horn Drill"),
    [MOVE_TACKLE] = _("Tackle"),
    [MOVE_BODY_SLAM] = _("Body Slam"),
    [MOVE_WRAP] = _("Wrap"),
    [MOVE_TAKE_DOWN] = _("Take Down"),
    [MOVE_THRASH] = _("Thrash"),
    [MOVE_DOUBLE_EDGE] = _("Double-Edge"),
    [MOVE_TAIL_WHIP] = _("Tail Whip"),
    [MOVE_POISON_STING] = _("Poison Sting"),
    [MOVE_TWINEEDLE] = _("Twineedle"),
    [MOVE_PIN_MISSILE] = _("Pin Missile"),
    [MOVE_LEER] = _("Leer"),
    [MOVE_BITE] = _("Bite"),
    [MOVE_GROWL] = _("Growl"),
    [MOVE_ROAR] = _("Roar"),
    [MOVE_SING] = _("Sing"),
    [MOVE_SUPERSONIC] = _("Supersonic"),
    [MOVE_SONIC_BOOM] = _("Sonicboom"),
    [MOVE_DISABLE] = _("Disable"),
    [MOVE_ACID] = _("Acid"),
    [MOVE_EMBER] = _("Ember"),
    [MOVE_FLAMETHROWER] = _("Flamethrower"),
    [MOVE_MIST] = _("Mist"),
    [MOVE_WATER_GUN] = _("Water Gun"),
    [MOVE_HYDRO_PUMP] = _("Hydro Pump"),
    [MOVE_SURF] = _("Surf"),
    [MOVE_ICE_BEAM] = _("Ice Beam"),
    [MOVE_BLIZZARD] = _("Blizzard"),
    [MOVE_PSYBEAM] = _("Psybeam"),
    [MOVE_BUBBLE_BEAM] = _("Bubble Beam"),
    [MOVE_AURORA_BEAM] = _("Aurora Beam"),
    [MOVE_HYPER_BEAM] = _("Hyper Beam"),
    [MOVE_PECK] = _("Peck"),
    [MOVE_DRILL_PECK] = _("Drill Peck"),
    [MOVE_SUBMISSION] = _("Submission"),
    [MOVE_LOW_KICK] = _("Low Kick"),
    [MOVE_COUNTER] = _("Counter"),
    [MOVE_SEISMIC_TOSS] = _("Seismic Toss"),
    [MOVE_STRENGTH] = _("Strength"),
    [MOVE_ABSORB] = _("Absorb"),
    [MOVE_MEGA_DRAIN] = _("Mega Drain"),
    [MOVE_LEECH_SEED] = _("Leech Seed"),
    [MOVE_GROWTH] = _("Growth"),
    [MOVE_RAZOR_LEAF] = _("Razor Leaf"),
    [MOVE_SOLAR_BEAM] = _("Solar Beam"),
    [MOVE_POISON_POWDER] = _("PoisonPowder"),
    [MOVE_STUN_SPORE] = _("Stun Spore"),
    [MOVE_SLEEP_POWDER] = _("Sleep Powder"),
    [MOVE_PETAL_DANCE] = _("Petal Dance"),
    [MOVE_STRING_SHOT] = _("String Shot"),
    [MOVE_DRAGON_RAGE] = _("Dragon Rage"),
    [MOVE_FIRE_SPIN] = _("Fire Spin"),
    [MOVE_THUNDER_SHOCK] = _("ThunderShock"),
    [MOVE_THUNDERBOLT] = _("Thunderbolt"),
    [MOVE_THUNDER_WAVE] = _("Thunder Wave"),
    [MOVE_THUNDER] = _("Thunder"),
    [MOVE_ROCK_THROW] = _("Rock Throw"),
    [MOVE_EARTHQUAKE] = _("Earthquake"),
    [MOVE_FISSURE] = _("Fissure"),
    [MOVE_DIG] = _("Dig"),
    [MOVE_TOXIC] = _("Toxic"),
    [MOVE_CONFUSION] = _("Confusion"),
    [MOVE_PSYCHIC] = _("Psychic"),
    [MOVE_HYPNOSIS] = _("Hypnosis"),
    [MOVE_MEDITATE] = _("Meditate"),
    [MOVE_AGILITY] = _("Agility"),
    [MOVE_QUICK_ATTACK] = _("Quick Attack"),
    [MOVE_RAGE] = _("Rage"),
    [MOVE_TELEPORT] = _("Teleport"),
    [MOVE_NIGHT_SHADE] = _("Night Shade"),
    [MOVE_MIMIC] = _("Mimic"),
    [MOVE_SCREECH] = _("Screech"),
    [MOVE_DOUBLE_TEAM] = _("Double Team"),
    [MOVE_RECOVER] = _("Recover"),
    [MOVE_HARDEN] = _("Harden"),
    [MOVE_MINIMIZE] = _("Minimize"),
    [MOVE_SMOKESCREEN] = _("Smokescreen"),
    [MOVE_CONFUSE_RAY] = _("Confuse Ray"),
    [MOVE_WITHDRAW] = _("Withdraw"),
    [MOVE_DEFENSE_CURL] = _("Defense Curl"),
    [MOVE_BARRIER] = _("Barrier"),
    [MOVE_LIGHT_SCREEN] = _("Light Screen"),
    [MOVE_HAZE] = _("Haze"),
    [MOVE_REFLECT] = _("Reflect"),
    [MOVE_FOCUS_ENERGY] = _("Focus Energy"),
    [MOVE_BIDE] = _("Bide"),
    [MOVE_METRONOME] = _("Metronome"),
    [MOVE_MIRROR_MOVE] = _("Mirror Move"),
    [MOVE_SELF_DESTRUCT] = _("SelfDestruct"),
    [MOVE_EGG_BOMB] = _("Egg Bomb"),
    [MOVE_LICK] = _("Lick"),
    [MOVE_SMOG] = _("Smog"),
    [MOVE_SLUDGE] = _("Sludge"),
    [MOVE_BONE_CLUB] = _("Bone Club"),
    [MOVE_FIRE_BLAST] = _("Fire Blast"),
    [MOVE_WATERFALL] = _("Waterfall"),
    [MOVE_CLAMP] = _("Clamp"),
    [MOVE_SWIFT] = _("Swift"),
    [MOVE_SKULL_BASH] = _("Skull Bash"),
    [MOVE_SPIKE_CANNON] = _("Spike Cannon"),
    [MOVE_CONSTRICT] = _("Constrict"),
    [MOVE_AMNESIA] = _("Amnesia"),
    [MOVE_KINESIS] = _("Kinesis"),
    [MOVE_SOFT_BOILED] = _("Soft-Boiled"),
    [MOVE_HI_JUMP_KICK] = _("Hi Jump Kick"),
    [MOVE_GLARE] = _("Glare"),
    [MOVE_DREAM_EATER] = _("Dream Eater"),
    [MOVE_POISON_GAS] = _("Poison Gas"),
    [MOVE_BARRAGE] = _("Barrage"),
    [MOVE_LEECH_LIFE] = _("Leech Life"),
    [MOVE_LOVELY_KISS] = _("Lovely Kiss"),
    [MOVE_SKY_ATTACK] = _("Sky Attack"),
    [MOVE_TRANSFORM] = _("Transform"),
    [MOVE_BUBBLE] = _("Bubble"),
    [MOVE_DIZZY_PUNCH] = _("Dizzy Punch"),
    [MOVE_SPORE] = _("Spore"),
    [MOVE_FLASH] = _("Flash"),
    [MOVE_PSYWAVE] = _("Psywave"),
    [MOVE_SPLASH] = _("Splash"),
    [MOVE_ACID_ARMOR] = _("Acid Armor"),
    [MOVE_CRABHAMMER] = _("Crabhammer"),
    [MOVE_EXPLOSION] = _("Explosion"),
    [MOVE_FURY_SWIPES] = _("Fury Swipes"),
    [MOVE_BONEMERANG] = _("Bonemerang"),
    [MOVE_REST] = _("Rest"),
    [MOVE_ROCK_SLIDE] = _("Rock Slide"),
    [MOVE_HYPER_FANG] = _("Hyper Fang"),
    [MOVE_SHARPEN] = _("Sharpen"),
    [MOVE_CONVERSION] = _("Conversion"),
    [MOVE_TRI_ATTACK] = _("Tri Attack"),
    [MOVE_SUPER_FANG] = _("Super Fang"),
    [MOVE_SLASH] = _("Slash"),
    [MOVE_SUBSTITUTE] = _("Substitute"),
    [MOVE_STRUGGLE] = _("Struggle"),
    [MOVE_SKETCH] = _("Sketch"),
    [MOVE_TRIPLE_KICK] = _("Triple Kick"),
    [MOVE_THIEF] = _("Thief"),
    [MOVE_SPIDER_WEB] = _("Spider Web"),
    [MOVE_MIND_READER] = _("Mind Reader"),
    [MOVE_NIGHTMARE] = _("Nightmare"),
    [MOVE_FLAME_WHEEL] = _("Flame Wheel"),
    [MOVE_SNORE] = _("Snore"),
    [MOVE_CURSE] = _("Curse"),
    [MOVE_FLAIL] = _("Flail"),
    [MOVE_CONVERSION_2] = _("Conversion 2"),
    [MOVE_AEROBLAST] = _("Aeroblast"),
    [MOVE_COTTON_SPORE] = _("Cotton Spore"),
    [MOVE_REVERSAL] = _("Reversal"),
    [MOVE_SPITE] = _("Spite"),
    [MOVE_POWDER_SNOW] = _("Powder Snow"),
    [MOVE_PROTECT] = _("Protect"),
    [MOVE_MACH_PUNCH] = _("Mach Punch"),
    [MOVE_SCARY_FACE] = _("Scary Face"),
    [MOVE_FAINT_ATTACK] = _("Feint Attack"),
    [MOVE_SWEET_KISS] = _("Sweet Kiss"),
    [MOVE_BELLY_DRUM] = _("Belly Drum"),
    [MOVE_SLUDGE_BOMB] = _("Sludge Bomb"),
    [MOVE_MUD_SLAP] = _("Mud-Slap"),
    [MOVE_OCTAZOOKA] = _("Octazooka"),
    [MOVE_SPIKES] = _("Spikes"),
    [MOVE_ZAP_CANNON] = _("Zap Cannon"),
    [MOVE_FORESIGHT] = _("Foresight"),
    [MOVE_DESTINY_BOND] = _("Destiny Bond"),
    [MOVE_PERISH_SONG] = _("Perish Song"),
    [MOVE_ICY_WIND] = _("Icy Wind"),
    [MOVE_DETECT] = _("Detect"),
    [MOVE_BONE_RUSH] = _("Bone Rush"),
    [MOVE_LOCK_ON] = _("Lock-On"),
    [MOVE_OUTRAGE] = _("Outrage"),
    [MOVE_SANDSTORM] = _("Sandstorm"),
    [MOVE_GIGA_DRAIN] = _("Giga Drain"),
    [MOVE_ENDURE] = _("Endure"),
    [MOVE_CHARM] = _("Charm"),
    [MOVE_ROLLOUT] = _("Rollout"),
    [MOVE_FALSE_SWIPE] = _("False Swipe"),
    [MOVE_SWAGGER] = _("Swagger"),
    [MOVE_MILK_DRINK] = _("Milk Drink"),
    [MOVE_SPARK] = _("Spark"),
    [MOVE_FURY_CUTTER] = _("Fury Cutter"),
    [MOVE_STEEL_WING] = _("Steel Wing"),
    [MOVE_MEAN_LOOK] = _("Mean Look"),
    [MOVE_ATTRACT] = _("Attract"),
    [MOVE_SLEEP_TALK] = _("Sleep Talk"),
    [MOVE_HEAL_BELL] = _("Heal Bell"),
    [MOVE_RETURN] = _("Return"),
    [MOVE_PRESENT] = _("Present"),
    [MOVE_FRUSTRATION] = _("Frustration"),
    [MOVE_SAFEGUARD] = _("Safeguard"),
    [MOVE_PAIN_SPLIT] = _("Pain Split"),
    [MOVE_SACRED_FIRE] = _("Sacred Fire"),
    [MOVE_MAGNITUDE] = _("Magnitude"),
    [MOVE_DYNAMIC_PUNCH] = _("DynamicPunch"),
    [MOVE_MEGAHORN] = _("Megahorn"),
    [MOVE_DRAGON_BREATH] = _("DragonBreath"),
    [MOVE_BATON_PASS] = _("Baton Pass"),
    [MOVE_ENCORE] = _("Encore"),
    [MOVE_PURSUIT] = _("Pursuit"),
    [MOVE_RAPID_SPIN] = _("Rapid Spin"),
    [MOVE_SWEET_SCENT] = _("Sweet Scent"),
    [MOVE_IRON_TAIL] = _("Iron Tail"),
    [MOVE_METAL_CLAW] = _("Metal Claw"),
    [MOVE_VITAL_THROW] = _("Vital Throw"),
    [MOVE_MORNING_SUN] = _("Morning Sun"),
    [MOVE_SYNTHESIS] = _("Synthesis"),
    [MOVE_MOONLIGHT] = _("Moonlight"),
    [MOVE_HIDDEN_POWER] = _("Hidden Power"),
    [MOVE_CROSS_CHOP] = _("Cross Chop"),
    [MOVE_TWISTER] = _("Twister"),
    [MOVE_RAIN_DANCE] = _("Rain Dance"),
    [MOVE_SUNNY_DAY] = _("Sunny Day"),
    [MOVE_CRUNCH] = _("Crunch"),
    [MOVE_MIRROR_COAT] = _("Mirror Coat"),
    [MOVE_PSYCH_UP] = _("Psych Up"),
    [MOVE_EXTREME_SPEED] = _("ExtremeSpeed"),
    [MOVE_ANCIENT_POWER] = _("AncientPower"),
    [MOVE_SHADOW_BALL] = _("Shadow Ball"),
    [MOVE_FUTURE_SIGHT] = _("Future Sight"),
    [MOVE_ROCK_SMASH] = _("Rock Smash"),
    [MOVE_WHIRLPOOL] = _("Whirlpool"),
    [MOVE_BEAT_UP] = _("Beat Up"),
    [MOVE_FAKE_OUT] = _("Fake Out"),
    [MOVE_UPROAR] = _("Uproar"),
    [MOVE_STOCKPILE] = _("Stockpile"),
    [MOVE_SPIT_UP] = _("Spit Up"),
    [MOVE_SWALLOW] = _("Swallow"),
    [MOVE_HEAT_WAVE] = _("Heat Wave"),
    [MOVE_HAIL] = _("Hail"),
    [MOVE_TORMENT] = _("Torment"),
    [MOVE_FLATTER] = _("Flatter"),
    [MOVE_WILL_O_WISP] = _("Will-O-Wisp"),
    [MOVE_MEMENTO] = _("Memento"),
    [MOVE_FACADE] = _("Facade"),
    [MOVE_FOCUS_PUNCH] = _("Focus Punch"),
    [MOVE_SMELLING_SALT] = _("SmellingSalt"),
    [MOVE_FOLLOW_ME] = _("Follow Me"),
    [MOVE_NATURE_POWER] = _("Nature Power"),
    [MOVE_CHARGE] = _("Charge"),
    [MOVE_TAUNT] = _("Taunt"),
    [MOVE_HELPING_HAND] = _("Helping Hand"),
    [MOVE_TRICK] = _("Trick"),
    [MOVE_ROLE_PLAY] = _("Role Play"),
    [MOVE_WISH] = _("Wish"),
    [MOVE_ASSIST] = _("Assist"),
    [MOVE_INGRAIN] = _("Ingrain"),
    [MOVE_SUPERPOWER] = _("Superpower"),
    [MOVE_MAGIC_COAT] = _("Magic Coat"),
    [MOVE_RECYCLE] = _("Recycle"),
    [MOVE_REVENGE] = _("Revenge"),
    [MOVE_BRICK_BREAK] = _("Brick Break"),
    [MOVE_YAWN] = _("Yawn"),
    [MOVE_KNOCK_OFF] = _("Knock Off"),
    [MOVE_ENDEAVOR] = _("Endeavor"),
    [MOVE_ERUPTION] = _("Eruption"),
    [MOVE_SKILL_SWAP] = _("Skill Swap"),
    [MOVE_IMPRISON] = _("Imprison"),
    [MOVE_REFRESH] = _("Refresh"),
    [MOVE_GRUDGE] = _("Grudge"),
    [MOVE_SNATCH] = _("Snatch"),
    [MOVE_SECRET_POWER] = _("Secret Power"),
    [MOVE_DIVE] = _("Dive"),
    [MOVE_ARM_THRUST] = _("Arm Thrust"),
    [MOVE_CAMOUFLAGE] = _("Camouflage"),
    [MOVE_TAIL_GLOW] = _("Tail Glow"),
    [MOVE_LUSTER_PURGE] = _("Luster Purge"),
    [MOVE_MIST_BALL] = _("Mist Ball"),
    [MOVE_FEATHER_DANCE] = _("FeatherDance"),
    [MOVE_TEETER_DANCE] = _("Teeter Dance"),
    [MOVE_BLAZE_KICK] = _("Blaze Kick"),
    [MOVE_MUD_SPORT] = _("Mud Sport"),
    [MOVE_ICE_BALL] = _("Ice Ball"),
    [MOVE_NEEDLE_ARM] = _("Needle Arm"),
    [MOVE_SLACK_OFF] = _("Slack Off"),
    [MOVE_HYPER_VOICE] = _("Hyper Voice"),
    [MOVE_POISON_FANG] = _("Poison Fang"),
    [MOVE_CRUSH_CLAW] = _("Crush Claw"),
    [MOVE_BLAST_BURN] = _("Blast Burn"),
    [MOVE_HYDRO_CANNON] = _("Hydro Cannon"),
    [MOVE_METEOR_MASH] = _("Meteor Mash"),
    [MOVE_ASTONISH] = _("Astonish"),
    [MOVE_WEATHER_BALL] = _("Weather Ball"),
    [MOVE_AROMATHERAPY] = _("Aromatherapy"),
    [MOVE_FAKE_TEARS] = _("Fake Tears"),
    [MOVE_AIR_CUTTER] = _("Air Cutter"),
    [MOVE_OVERHEAT] = _("Overheat"),
    [MOVE_ODOR_SLEUTH] = _("Odor Sleuth"),
    [MOVE_ROCK_TOMB] = _("Rock Tomb"),
    [MOVE_SILVER_WIND] = _("Silver Wind"),
    [MOVE_METAL_SOUND] = _("Metal Sound"),
    [MOVE_GRASS_WHISTLE] = _("GrassWhistle"),
    [MOVE_TICKLE] = _("Tickle"),
    [MOVE_COSMIC_POWER] = _("Cosmic Power"),
    [MOVE_WATER_SPOUT] = _("Water Spout"),
    [MOVE_SIGNAL_BEAM] = _("Signal Beam"),
    [MOVE_SHADOW_PUNCH] = _("Shadow Punch"),
    [MOVE_EXTRASENSORY] = _("Extrasensory"),
    [MOVE_SKY_UPPERCUT] = _("Sky Uppercut"),
    [MOVE_SAND_TOMB] = _("Sand Tomb"),
    [MOVE_SHEER_COLD] = _("Sheer Cold"),
    [MOVE_MUDDY_WATER] = _("Muddy Water"),
    [MOVE_BULLET_SEED] = _("Bullet Seed"),
    [MOVE_AERIAL_ACE] = _("Aerial Ace"),
    [MOVE_ICICLE_SPEAR] = _("Icicle Spear"),
    [MOVE_IRON_DEFENSE] = _("Iron Defense"),
    [MOVE_BLOCK] = _("Block"),
    [MOVE_HOWL] = _("Howl"),
    [MOVE_DRAGON_CLAW] = _("Dragon Claw"),
    [MOVE_FRENZY_PLANT] = _("Frenzy Plant"),
    [MOVE_BULK_UP] = _("Bulk Up"),
    [MOVE_BOUNCE] = _("Bounce"),
    [MOVE_MUD_SHOT] = _("Mud Shot"),
    [MOVE_POISON_TAIL] = _("Poison Tail"),
    [MOVE_COVET] = _("Covet"),
    [MOVE_VOLT_TACKLE] = _("Volt Tackle"),
    [MOVE_MAGICAL_LEAF] = _("Magical Leaf"),
    [MOVE_WATER_SPORT] = _("Water Sport"),
    [MOVE_CALM_MIND] = _("Calm Mind"),
    [MOVE_LEAF_BLADE] = _("Leaf Blade"),
    [MOVE_DRAGON_DANCE] = _("Dragon Dance"),
    [MOVE_ROCK_BLAST] = _("Rock Blast"),
    [MOVE_SHOCK_WAVE] = _("Shock Wave"),
    [MOVE_WATER_PULSE] = _("Water Pulse"),
    [MOVE_DOOM_DESIRE] = _("Doom Desire"),
    [MOVE_PSYCHO_BOOST] = _("Psycho Boost"),
	[MOVE_ENERGY_BALL] = _("Energy Ball"),
	[MOVE_LEAF_STORM] = _("Leaf Storm"),
	[MOVE_DUAL_CHOP] = _("Dual Chop"),
	[MOVE_X_SCISSOR] = _("X-Scissor"),
    [MOVE_FLAME_BURST] = _("Flame Burst"),
    [MOVE_FLAME_CHARGE] = _("Flame Charge"),
    [MOVE_FLARE_BLITZ] = _("Flare Blitz"),
    [MOVE_BRAVE_BIRD] = _("Brave Bird"),
    [MOVE_MUD_BOMB] = _("Mud Bomb"),
    [MOVE_HAMMER_ARM] = _("Hammer Arm"),
    [MOVE_SUCKER_PUNCH] = _("Sucker Punch"),
    [MOVE_PLAY_ROUGH] = _("Play Rough"),
    [MOVE_SNARL] = _("Snarl"),
    [MOVE_FIRE_FANG] = _("Fire Fang"),
    [MOVE_THUNDER_FANG] = _("Thunder Fang"),
    [MOVE_ICE_FANG] = _("Ice Fang"),
    [MOVE_PUPPY_EYES] = _("Puppy Eyes"),
    [MOVE_FLING] = _("Fling"),
    [MOVE_SWITCHEROO] = _("Switcheroo"),
    [MOVE_BUG_BITE] = _("Bug Bite"),
    [MOVE_BUG_BUZZ] = _("Bug Buzz"),
    [MOVE_QUIVER_DANCE] = _("Quiver Dance"),
    [MOVE_VENOSHOCK] = _("Venoshock"),
	[MOVE_NATURAL_GIFT] = _("Natural Gift"),
	[MOVE_ZEN_HEADBUTT] = _("Zen Headbutt"),
	[MOVE_POWER_GEM] = _("Power Gem"),
	[MOVE_EARTH_POWER] = _("Earth Power"),
	[MOVE_NASTY_PLOT] = _("Nasty Plot"),
	[MOVE_LEAF_TORNADO] = _("Leaf Tornado"),
	[MOVE_HURRICANE] = _("Hurricane"),
	[MOVE_SHADOW_SNEAK] = _("Shadow Sneak"),
	[MOVE_PHANTOM_FORCE] = _("PhantomForce"),
	[MOVE_DEFOG] = _("Defog"),
	[MOVE_AIR_SLASH] = _("Air Slash"),
	[MOVE_PLUCK] = _("Pluck"),
	[MOVE_ROOST] = _("Roost"),
	[MOVE_PAYBACK] = _("Payback"),
	[MOVE_BRINE] = _("Brine"),
	[MOVE_TAILWIND] = _("Tailwind"),
	[MOVE_DISARM_VOICE] = _("Disarm Voice"),
	[MOVE_DRAIN_KISS] = _("Drain Kiss"),
	[MOVE_MOONBLAST] = _("Moonblast"),
	[MOVE_LUCKY_CHANT] = _("Lucky Chant"),
	[MOVE_STORED_POWER] = _("Stored Power"),
	[MOVE_CAPTIVATE] = _("Captivate"),
	[MOVE_HEAL_PULSE] = _("Heal Pulse"),
	[MOVE_HEALING_WISH] = _("Healing Wish"),
	[MOVE_AQUA_JET] = _("Aqua Jet"),
	[MOVE_STICKY_WEB] = _("Sticky Web"),
	[MOVE_OMINOUS_WIND] = _("Ominous Wind"),
	[MOVE_WORRY_SEED] = _("Worry Seed"),
	[MOVE_SEED_BOMB] = _("Seed Bomb"),
	[MOVE_FORCE_PALM] = _("Force Palm"),
	[MOVE_CHIP_AWAY] = _("Chip Away"),
	[MOVE_PUNISHMENT] = _("Punishment"),
	[MOVE_MIRACLE_EYE] = _("Miracle Eye"),
	[MOVE_PSYCHO_CUT] = _("Psycho Cut"),
	[MOVE_ECHOED_VOICE] = _("Echoed Voice"),
	[MOVE_SYNCHRONOISE] = _("Synchronoise"),
	[MOVE_BOOMBURST] = _("Boomburst"),
	[MOVE_WAKE_UP_SLAP] = _("Wake-Up Slap"),
	[MOVE_CLOSE_COMBAT] = _("Close Combat"),
	[MOVE_HEAVY_SLAM] = _("Heavy Slam"),
	[MOVE_AQUA_RING] = _("Aqua Ring"),
	[MOVE_SOAK] = _("Soak"),
	[MOVE_POISON_JAB] = _("Poison Jab"),
	[MOVE_AQUA_TAIL] = _("Aqua Tail"),
	[MOVE_ROCK_POLISH] = _("Rock Polish"),
	[MOVE_BULLDOZE] = _("Bulldoze"),
	[MOVE_STEALTH_ROCK] = _("Stealth Rock"),
	[MOVE_STONE_EDGE] = _("Stone Edge"),
	[MOVE_STEAMROLLER] = _("Steamroller"),
	[MOVE_DISCHARGE] = _("Discharge"),
	[MOVE_COPYCAT] = _("Copycat"),
	[MOVE_CROSS_POISON] = _("Cross Poison"),
	[MOVE_TOXIC_SPIKES] = _("Toxic Spikes"),
	[MOVE_ACID_SPRAY] = _("Acid Spray"),
	[MOVE_HEX] = _("Hex"),
	[MOVE_SLUDGE_WAVE] = _("Sludge Wave"),
	[MOVE_WRING_OUT] = _("Wring Out"),
	[MOVE_REFLECT_TYPE] = _("Reflect Type"),
	[MOVE_SHADOW_CLAW] = _("Shadow Claw"),
	[MOVE_FOUL_PLAY] = _("Foul Play"),
	[MOVE_FAIRY_WIND] = _("Fairy Wind"),
	[MOVE_IRON_HEAD] = _("Iron Head"),
	[MOVE_AUTOTOMIZE] = _("Autotomize"),
	[MOVE_METAL_BURST] = _("Metal Burst"),
	[MOVE_LOW_SWEEP] = _("Low Sweep"),
	[MOVE_WILD_CHARGE] = _("Wild Charge"),
	[MOVE_NUZZLE] = _("Nuzzle"),
	[MOVE_PLAY_NICE] = _("Play Nice"),
	[MOVE_ELECTRO_BALL] = _("Electro Ball"),
	[MOVE_ENTRAINMENT] = _("Entrainment"),
	[MOVE_TRUMP_CARD] = _("Trump Card"),
	[MOVE_STRUGGLE_BUG] = _("Struggle Bug"),
	[MOVE_INFESTATION] = _("Infestation"),
	[MOVE_PETAL_STORM] = _("Petal Storm"),
	[MOVE_GUNK_SHOT] = _("Gunk Shot"),
	[MOVE_VENOM_DRENCH] = _("Venom Drench"),
	[MOVE_BELCH] = _("Belch"),
	[MOVE_LAVA_PLUME] = _("Lava Plume"),
	[MOVE_INCINERATE] = _("Incinerate"),
	[MOVE_CLEAR_SMOG] = _("Clear Smog"),
	[MOVE_SHELL_SMASH] = _("Shell Smash"),
	[MOVE_INFERNO] = _("Inferno"),
	[MOVE_GYRO_BALL] = _("Gyro Ball"),
	[MOVE_DOUBLE_HIT] = _("Double Hit"),
	[MOVE_PSYSHOCK] = _("Psyshock"),
	[MOVE_NIGHT_SLASH] = _("Night Slash"),
	[MOVE_FEINT] = _("Feint"),
	[MOVE_DRAGON_TAIL] = _("Dragon Tail"),
	[MOVE_DRAGON_RUSH] = _("Dragon Rush"),
	[MOVE_SPIKY_SHIELD] = _("Spiky Shield"),
	[MOVE_COTTON_GUARD] = _("Cotton Guard"),
	[MOVE_DRAGON_PULSE] = _("Dragon Pulse"),
	[MOVE_HONE_CLAWS] = _("Hone Claws"),
	[MOVE_COIL] = _("Coil"),
	[MOVE_EERIE_IMPULSE] = _("EerieImpulse"),
	[MOVE_CHARGE_BEAM] = _("Charge Beam"),
	[MOVE_MAGNET_BOMB] = _("Magnet Bomb"),
	[MOVE_MIRROR_SHOT] = _("Mirror Shot"),
	[MOVE_FLASH_CANNON] = _("Flash Cannon"),
	[MOVE_NOBLE_ROAR] = _("Noble Roar"),
	[MOVE_RAZOR_SHELL] = _("Razor Shell"),
	[MOVE_POWER_TRICK] = _("Power Trick"),
	[MOVE_POWER_SPLIT] = _("Power Split"),
	[MOVE_GUARD_SPLIT] = _("Guard Split"),
	[MOVE_SPOTLIGHT] = _("Spotlight"),
	[MOVE_ACUPRESSURE] = _("Acupressure"),
	[MOVE_ME_FIRST] = _("Me First"),
	[MOVE_PSYCHO_SHIFT] = _("Psycho Shift"),
	[MOVE_POWER_SWAP] = _("Power Swap"),
	[MOVE_GUARD_SWAP] = _("Guard Swap"),
};

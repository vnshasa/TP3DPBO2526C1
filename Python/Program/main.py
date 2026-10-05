from actor import Actor
from director import Director
from drama import Drama
from drama_catalog import DramaCatalog
from episode import Episode
from writer import Writer


def print_banner(text: str) -> None:
    print("\n" + "=" * 64)
    print(f"  {text}")
    print("=" * 64 + "\n")


def create_reply_1988(director: Director, writer: Writer,
                      actor1: Actor, actor2: Actor, actor3: Actor) -> Drama:
    drama = Drama("Reply 1988", 2015, "Family, Romance, Drama", "tvN", director, writer)
    drama.set_cast([actor1, actor2, actor3])

    episodes = [
        Episode(1, "Hand in Hand", 84, 6.118),
        Episode(2, "The One Thing You're Mistaken About Me", 85, 6.836),
        Episode(3, "Not Guilty If You're Rich, Guilty If You're Poor", 81, 7.777),
        Episode(4, "Can't Help~ ing", 71, 8.251),
        Episode(5, "Ready for Winter", 86, 10.145),
        Episode(6, "The First Snow Is Coming", 77, 9.263),
        Episode(7, "To You", 88, 11.035),
        Episode(8, "Warm Words", 86, 11.293),
        Episode(9, "Crossing the Line", 92, 11.563),
        Episode(10, "Memory", 79, 13.360),
        Episode(11, "Three Prophecies", 99, 12.228),
        Episode(12, "What It Means To Love Someone", 91, 13.060),
        Episode(13, "Superman is Back", 95, 12.858),
        Episode(14, "Don't Worry, My Dear", 93, 15.133),
        Episode(15, "Between Love and Friendship", 94, 15.192),
        Episode(16, "Life is an Irony - Part I", 92, 15.372),
        Episode(17, "Life is an Irony - Part II", 105, 15.472),
        Episode(18, "Goodbye, My First Love", 97, 17.191),
        Episode(19, "You Did Your Best", 107, 17.597)
    ]
    drama.set_episodes(episodes)
    return drama


def create_crash_landing_on_you(director: Director, writer: Writer,
                                actor1: Actor, actor2: Actor, actor3: Actor) -> Drama:
    drama = Drama("Crash Landing on You", 2019, "Romance, Drama", "tvN", director, writer)
    drama.set_cast([actor1, actor2, actor3])

    episodes = [
        Episode(1, "Episode 1", 71, 6.074),
        Episode(2, "Episode 2", 78, 6.845),
        Episode(3, "Episode 3", 71, 7.414),
        Episode(4, "Episode 4", 79, 8.499),
        Episode(5, "Episode 5", 81, 8.730),
        Episode(6, "Episode 6", 80, 9.223),
        Episode(7, "Episode 7", 83, 9.394),
        Episode(8, "Episode 8", 87, 11.349),
        Episode(9, "Episode 9", 89, 11.516),
        Episode(10, "Episode 10", 85, 14.633),
        Episode(11, "Episode 11", 88, 14.238),
        Episode(12, "Episode 12", 97, 15.933),
        Episode(13, "Episode 13", 86, 14.097),
        Episode(14, "Episode 14", 92, 17.705),
        Episode(15, "Episode 15", 86, 17.066),
        Episode(16, "Episode 16", 113, 21.683)
    ]
    drama.set_episodes(episodes)
    return drama


def create_hospital_playlist(director: Director, writer: Writer,
                             actor1: Actor, actor2: Actor, actor3: Actor) -> Drama:
    drama = Drama("Hospital Playlist", 2020, "Medical, Comedy, Drama", "tvN", director, writer)
    drama.set_cast([actor1, actor2, actor3])

    episodes = [
        Episode(1, "Episode 1", 83, 6.325),
        Episode(2, "Episode 2", 82, 7.750),
        Episode(3, "Episode 3", 88, 8.556),
        Episode(4, "Episode 4", 79, 9.754),
        Episode(5, "Episode 5", 73, 11.321),
        Episode(6, "Episode 6", 82, 11.682),
        Episode(7, "Episode 7", 84, 12.077),
        Episode(8, "Episode 8", 88, 12.008),
        Episode(9, "Episode 9", 76, 12.134),
        Episode(10, "Episode 10", 92, 12.701),
        Episode(11, "Episode 11", 88, 13.125),
        Episode(12, "Episode 12", 113, 14.142)
    ]
    drama.set_episodes(episodes)
    return drama


def main() -> None:
    # Objek agregat dibuat di luar Drama.
    reply_director = Director("Shin Won-ho", 50, 2007, "Family dan ensemble storytelling", 2)
    reply_writer = Writer("Lee Woo-jung", 50, 2001, "Lee Woo-jung", "Family, Coming-of-age, Romance")
    reply_actor1 = Actor("Lee Hye-ri", 21, 2010, "DreamT Entertainment", "Sung Deok-sun", "Lead")
    reply_actor2 = Actor("Park Bo-gum", 22, 2011, "Blossom Entertainment", "Choi Taek", "Lead")
    reply_actor3 = Actor("Ryu Jun-yeol", 29, 2015, "C-JeS Entertainment", "Kim Jung-hwan", "Second Lead")

    crash_director = Director("Lee Jung-hyo", 48, 2008, "Romance dan human-centered drama", 0)
    crash_writer = Writer("Park Ji-eun", 50, 2000, "Park Ji-eun", "Romance, Comedy-Drama")
    crash_actor1 = Actor("Hyun Bin", 43, 2003, "VAST Entertainment", "Ri Jeong-hyeok", "Lead")
    crash_actor2 = Actor("Son Ye-jin", 44, 2000, "MSteam Entertainment", "Yoon Se-ri", "Lead")
    crash_actor3 = Actor("Seo Ji-hye", 41, 2003, "Culture Depot", "Seo Dan", "Second Lead")

    drama1 = create_reply_1988(reply_director, reply_writer, reply_actor1, reply_actor2, reply_actor3)
    drama2 = create_crash_landing_on_you(crash_director, crash_writer, crash_actor1, crash_actor2, crash_actor3)

    catalog = DramaCatalog("K-Drama Hub")
    catalog.set_dramas([drama1, drama2])

    print_banner("DATA SEBELUM PENAMBAHAN")
    catalog.display_all()

    print_banner("PROSES PENAMBAHAN DATA")

    reply1988 = catalog.find_drama("Reply 1988")
    if reply1988 is not None:
        episodes = list(reply1988.get_episodes())
        episodes.append(Episode(20, "Goodbye, My Youth. Goodbye, Ssangmun-dong", 108, 18.803))
        reply1988.set_episodes(episodes)
        print('[+] Episode 20 "Goodbye, My Youth. Goodbye, Ssangmun-dong" ditambahkan ke "Reply 1988"')

    new_actor = Actor("Kim Jung-hyun", 36, 2015, "Story J Company", "Goo Seung-jun", "Supporting")
    crash_landing = catalog.find_drama("Crash Landing on You")
    if crash_landing is not None:
        cast = list(crash_landing.get_cast())
        cast.append(new_actor)
        crash_landing.set_cast(cast)
        print('[+] Pemeran "Kim Jung-hyun" ditambahkan ke "Crash Landing on You"')

    hospital_actor1 = Actor("Cho Jung-seok", 44, 2004, "JAM Entertainment", "Lee Ik-jun", "Lead")
    hospital_actor2 = Actor("Yoo Yeon-seok", 41, 2003, "King Kong by Starship", "Ahn Jeong-won", "Lead")
    hospital_actor3 = Actor("Jung Kyung-ho", 42, 2004, "Management Allum", "Kim Joon-wan", "Second Lead")
    drama3 = create_hospital_playlist(reply_director, reply_writer,
                                      hospital_actor1, hospital_actor2, hospital_actor3)

    dramas = list(catalog.get_dramas())
    dramas.append(drama3)
    catalog.set_dramas(dramas)
    print('[+] Drama baru "Hospital Playlist" ditambahkan ke katalog')

    print_banner("DATA SESUDAH PENAMBAHAN")
    catalog.display_all()


if __name__ == "__main__":
    main()

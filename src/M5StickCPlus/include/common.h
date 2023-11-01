void drawHeader(esphome::display::DisplayBuffer& it, esphome::display::Font* font) {

  int i = 0;
  int j = 0;
  int dbm = 0;

  it.rectangle(10, 3, 38, 17, white);
  it.filled_rectangle(48, 8, 3, 8, white);

  if (id(niveau_batterie).has_state()) {
    for (i=0; i<4; i++) {
      if (id(niveau_batterie).state > 10+i*25 ) {
        it.filled_rectangle(14+i*8, 7, 6, 9, white);
      }
    }
  }

  if (id(signal_wifi).has_state()) {
    if (id(signal_wifi).state <= -100)
    {
      dbm = 0;
    }
    else if (id(signal_wifi).state >= -50)
    {
      dbm = 100;
    } else {
      dbm = (id(signal_wifi).state + 100);
    }
    for (i = 0; i < 4; i++)
    {
      for (j = 0; j < 3 * (i + 1); j++)
      {
        if (dbm > i * 25)
        {
          it.draw_pixel_at(220+3*i, 17-j, white);
          it.draw_pixel_at(220+1+3*i, 17-j, white);
        }
      }
    }
  } else {
    it.print(220, 1, font, red, TextAlign::TOP_LEFT, "X");
  }

  it.strftime(150, 1, font, white, TextAlign::TOP_LEFT, "%H:%M", id(sntp_time).now());

}

void drawFooter(esphome::display::DisplayBuffer& it, esphome::display::Font* font) {
  it.print(10, 135, font, red, TextAlign::BOTTOM_LEFT, id(msgBeep).c_str());
}
